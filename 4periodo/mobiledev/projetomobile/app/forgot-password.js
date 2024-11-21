import React, { useState } from 'react';
import { View, TextInput, Button, StyleSheet, Alert } from 'react-native';
import { useRouter } from 'expo-router';
import { supabase } from '../lib/supabase'; // Importe seu arquivo de configuração do supabase

const ForgotPasswordScreen = () => {
  const [email, setEmail] = useState('');
  const [loading, setLoading] = useState(false);
  const router = useRouter();

  // Função para enviar o e-mail de redefinição de senha
  const handleResetPassword = async () => {
    if (!email) {
      Alert.alert('Erro', 'Por favor, insira seu e-mail.');
      return;
    }

    setLoading(true);
    try {
      const { error } = await supabase.auth.resetPasswordForEmail(email);

      if (error) {
        Alert.alert('Erro', error.message);
      } else {
        Alert.alert('Sucesso', 'Verifique sua caixa de entrada para redefinir sua senha.');
        router.push('/login'); // Redireciona para a tela de login após o envio
      }
    } catch (error) {
      Alert.alert('Erro', 'Ocorreu um erro ao tentar enviar o e-mail de redefinição.');
    } finally {
      setLoading(false);
    }
  };

  return (
    <View style={styles.container}>
      <TextInput
        style={styles.input}
        placeholder="Digite seu e-mail"
        value={email}
        onChangeText={setEmail}
      />
      <Button
        title={loading ? 'Enviando...' : 'Redefinir Senha'}
        onPress={handleResetPassword}
        disabled={loading}
      />
      {/* Botão para voltar ao Login */}
      <Button
        title="Voltar para Login"
        onPress={() => router.push('/login')}
      />
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
  input: {
    width: '100%',
    height: 40,
    borderColor: '#ccc',
    borderWidth: 1,
    borderRadius: 5,
    marginBottom: 10,
    paddingLeft: 10,
  },
});

export default ForgotPasswordScreen;
