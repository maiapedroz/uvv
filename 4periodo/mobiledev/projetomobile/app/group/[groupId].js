import React, { useEffect, useState } from 'react';
import { View, Text, StyleSheet, Button, ActivityIndicator, FlatList } from 'react-native';
import { useRouter, useLocalSearchParams } from 'expo-router'; // useLocalSearchParams para parâmetros dinâmicos
import { supabase } from '../../lib/supabase';

const GroupDetails = () => {
  const [group, setGroup] = useState(null);
  const [students, setStudents] = useState([]);
  const [evaluation, setEvaluation] = useState(null);
  const [loading, setLoading] = useState(true);
  const { groupId } = useLocalSearchParams(); // Obtém o ID do grupo da rota
  const router = useRouter();

  useEffect(() => {
    const fetchGroupDetails = async () => {
      try {
        // Busca os dados do grupo
        const { data: groupData, error: groupError } = await supabase
          .from('groups')
          .select('*')
          .eq('id', groupId)
          .single(); // Busca o grupo pelo ID

        if (groupError) throw groupError;

        // Busca os alunos do grupo
        const { data: studentsData, error: studentsError } = await supabase
          .from('alunos') // Ajuste para a tabela de alunos
          .select('nome, matricula')
          .eq('grupo_id', groupId); // Supondo que o ID do grupo está na tabela de alunos

        if (studentsError) throw studentsError;

        // Busca a avaliação do grupo
        const { data: evaluationData, error: evaluationError } = await supabase
          .from('avaliacao') // Ajuste para a tabela de avaliações
          .select('nota')
          .eq('grupo_id', groupId) // Supondo que o ID do grupo está na tabela de avaliações
          .single(); // Caso haja apenas uma avaliação por grupo

        if (evaluationError) throw evaluationError;

        setGroup(groupData);
        setStudents(studentsData);
        setEvaluation(evaluationData);

      } catch (error) {
        console.error('Erro ao buscar detalhes do grupo:', error.message);
      } finally {
        setLoading(false);
      }
    };

    if (groupId) {
      fetchGroupDetails();
    }
  }, [groupId]);

  if (loading) {
    return <ActivityIndicator size="large" color="#007BFF" />;
  }

  if (!group) {
    return (
      <View style={styles.container}>
        <Text style={styles.errorText}>Grupo não encontrado.</Text>
        <Button title="Voltar para Grupos" onPress={() => router.push('/groups')} />
      </View>
    );
  }

  return (
    <View style={styles.container}>
      <Text style={styles.title}>{group.nome}</Text>
      <Text style={styles.description}>{group.description || 'Sem descrição disponível.'}</Text>

      <Text style={styles.subTitle}>Alunos:</Text>
      {students.length > 0 ? (
        <FlatList
          data={students}
          renderItem={({ item }) => (
            <View style={styles.studentItem}>
              <Text>Nome: {item.nome}</Text>
              <Text>Matricula: {item.matricula}</Text>
            </View>
          )}
          keyExtractor={(item) => item.matricula}
        />
      ) : (
        <Text>Nenhum aluno encontrado.</Text>
      )}

      <Text style={styles.subTitle}>Avaliação:</Text>
      {evaluation ? (
        <Text style={styles.evaluation}>Nota: {evaluation.nota}</Text>
      ) : (
        <Text>Nenhuma avaliação disponível.</Text>
      )}

      <Button title="Voltar para Grupos" onPress={() => router.push('/groups')} />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'flex-start',
    alignItems: 'center',
    padding: 20,
  },
  title: {
    fontSize: 24,
    fontWeight: 'bold',
    marginBottom: 10,
  },
  description: {
    fontSize: 16,
    color: '#333',
    marginBottom: 20,
  },
  subTitle: {
    fontSize: 18,
    fontWeight: 'bold',
    marginTop: 20,
  },
  studentItem: {
    marginBottom: 10,
    padding: 5,
    backgroundColor: '#f0f0f0',
    borderRadius: 5,
    width: '100%',
  },
  evaluation: {
    fontSize: 16,
    fontWeight: 'bold',
    color: '#007BFF',
    marginTop: 10,
  },
  errorText: {
    fontSize: 18,
    color: 'red',
  },
});

export default GroupDetails;
