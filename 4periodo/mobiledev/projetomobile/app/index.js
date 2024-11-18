// app/index.js
import React, { useEffect, useState } from 'react';
import { useRouter } from 'expo-router';

export default function Index() {
  const router = useRouter();
  const [isReady, setIsReady] = useState(false);

  useEffect(() => {
    // Marcar como pronto para navegação
    setIsReady(true);
  }, []);

  useEffect(() => {
    // Se o layout estiver pronto, redireciona para login
    if (isReady) {
      router.push('/login');
    }
  }, [isReady, router]);

  return null; // Nada a renderizar aqui, apenas navegação
}
