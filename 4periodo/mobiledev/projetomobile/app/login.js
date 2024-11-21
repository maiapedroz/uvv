import React, { useState, useEffect } from 'react';
import { View, TextInput, Button, StyleSheet, Text } from 'react-native';
import { supabase } from '../lib/supabase'; // Corrigido para não usar a extensão .ts
import { useRouter } from 'expo-router';

const LoginScreen = () => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');
  const router = useRouter();

  // Verifica se supabase foi carregado corretamente
  useEffect(() => {
    if (!supabase || !supabase.auth) {
      console.error('Supabase não foi inicializado corretamente');
    }
  }, []);

  const handleLogin = async () => {
    // Verifica novamente se supabase.auth está disponível
    if (!supabase?.auth) {
      setError('Erro ao inicializar autenticação');
      return;
    }

    const { data, error } = await supabase.auth.signInWithPassword({
      email,
      password,
    });

    if (error) {
      setError(error.message);
    } else {
      router.push('/home');
    }
  };

  const handleNavigateToGroups = () => {
    router.push('/groups'); // Navega para a tela de grupos
  };

  return (
    <View style={styles.container}>
      <TextInput
        style={styles.input}
        placeholder="Email"
        value={email}
        onChangeText={setEmail}
      />
      <TextInput
        style={styles.input}
        placeholder="Senha"
        secureTextEntry
        value={password}
        onChangeText={setPassword}
      />
      {error ? <Text style={styles.error}>{error}</Text> : null}
      <Button title="Entrar" onPress={handleLogin} />
      <Button title="Criar Conta" onPress={() => router.push('/register')} />
      <Button 
        title="Esqueci minha Senha" 
        onPress={() => router.push('/forgot-password')} 
      />
      
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    padding: 20,
  },
  input: {
    width: '100%',
    height: 40,
    borderColor: '#ccc',
    borderWidth: 1,
    marginBottom: 10,
    paddingLeft: 10,
  },
  error: {
    color: 'red',
    marginBottom: 10,
  },
});

export default LoginScreen;
