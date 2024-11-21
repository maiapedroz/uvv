import React, { useEffect, useState } from 'react';
import { View, Text, Button, StyleSheet, TouchableOpacity, Alert } from 'react-native';
import { useRouter } from 'expo-router';
import { supabase } from '../lib/supabase'; // Certifique-se de que está importando o supabase corretamente

const GroupsScreen = () => {
  const [session, setSession] = useState(null);
  const [groups, setGroups] = useState([]); // Inicializando o estado de grupos
  const router = useRouter();

  // Função para buscar os grupos do banco de dados
  const fetchGroups = async () => {
    try {
      const { data, error } = await supabase
        .from('groups') // Nome da tabela no Supabase
        .select('id, nome'); // Certifique-se de que os campos estão corretos

      if (error) {
        throw error;
      }

      if (data) {
        setGroups(data); // Atualiza o estado com os grupos
      } else {
        Alert.alert('Nenhum grupo encontrado');
      }
    } catch (error) {
      Alert.alert('Erro', 'Erro ao carregar grupos');
    }
  };

  // Verifica se o usuário está autenticado e carrega os grupos
  useEffect(() => {
    const fetchSession = async () => {
      const { data: { session } } = await supabase.auth.getSession();
      setSession(session);

      if (!session) {
        router.push('/login'); // Redireciona para login se não houver sessão
      } else {
        fetchGroups(); // Chama a função para buscar grupos se estiver autenticado
      }
    };

    fetchSession();
  }, [router]);

  if (!session) {
    return null; // Não renderiza nada até a sessão estar carregada
  }

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Grupos</Text>
      {groups.length > 0 ? (
        groups.map(group => (
          <TouchableOpacity 
            key={group.id} 
            onPress={() => router.push(`/group/${group.id}`)} // Navega para a rota dinâmica
          >
            <Text style={styles.groupName}>{group.nome}</Text>
          </TouchableOpacity>
        ))
      ) : (
        <Text style={styles.noGroupsText}>Nenhum grupo encontrado</Text>
      )}
  
      <Button title="Voltar para a Home" onPress={() => router.push('/home')} />
    </View>
  );
  
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#f5f5f5',
    padding: 20,
  },
  title: {
    fontSize: 24,
    fontWeight: 'bold',
    marginBottom: 20,
  },
  groupName: {
    fontSize: 18,
    color: '#007BFF',
    marginBottom: 10,
  },
  noGroupsText: {
    fontSize: 16,
    color: 'gray',
  },
});

export default GroupsScreen;
