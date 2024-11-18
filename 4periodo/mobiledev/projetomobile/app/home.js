import React from 'react';
import { View, Text, Button, StyleSheet, Alert } from 'react-native';
import { useRouter } from 'expo-router';
import { supabase } from '../lib/supabase'; // Certifique-se de importar o supabase corretamente

const HomeScreen = () => {
  const router = useRouter();

  // Função de Logout
  const handleLogout = async () => {
    try {
      await supabase.auth.signOut(); // Desconectar o usuário
      Alert.alert("Você foi desconectado!");
      router.push('/login'); // Redireciona para a tela de login
    } catch (error) {
      Alert.alert("Erro", "Ocorreu um erro ao tentar desconectar.");
    }
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Bem-vindo à Home</Text>
      <Button title="Ver Grupos" onPress={() => router.push('/groups')} />
      <Button title="Logout" onPress={handleLogout} />
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
});

export default HomeScreen;
