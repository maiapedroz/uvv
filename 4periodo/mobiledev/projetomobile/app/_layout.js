import React, { useState, useEffect } from 'react';
import { Stack } from 'expo-router';
import { useRouter } from 'expo-router';
import { supabase } from '../lib/supabase'; // Certifique-se de que está exportando corretamente de supabase.js

export default function RootLayout() {
  const [session, setSession] = useState(null);
  const [isReady, setIsReady] = useState(false); // Adicionando um estado para aguardar o carregamento da sessão
  const router = useRouter();

  useEffect(() => {
    const fetchSession = async () => {
      // Recupera a sessão do Supabase
      const { data: { session } } = await supabase.auth.getSession(); // Método assíncrono
      setSession(session); // Atualiza o estado da sessão

      // Define o listener para mudanças de sessão
      const { data: listener } = supabase.auth.onAuthStateChange((_event, session) => {
        setSession(session); // Atualiza a sessão em tempo real
      });

      setIsReady(true); // Marca como pronto após recuperar a sessão

      // Limpeza do listener
      return () => {
        listener?.unsubscribe(); // Limpa o listener quando o componente for desmontado
      };
    };

    fetchSession();
  }, []);

  useEffect(() => {
    // Quando a sessão estiver pronta, redireciona para a tela correta
    if (isReady) {
      if (!session) {
        router.push('/login'); // Se não houver sessão, vai para login
      } else {
        router.push('/home'); // Se houver sessão, vai para home
      }
    }
  }, [isReady, session, router]);

  // Enquanto a sessão não for carregada, não renderiza nada
  if (!isReady) {
    return null; // Não renderiza nada até que a sessão esteja carregada
  }

  return (
    <Stack screenOptions={{ headerShown: false }} />
  );
}
