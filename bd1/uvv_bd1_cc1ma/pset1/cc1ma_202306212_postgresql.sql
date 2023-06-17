
--Script para gerar o banco de dados 'uvv' no postgres do PSET1, do professor Abrantes.
--Aluno: Pedro Maia Dantas Nunes
--Matrícula: 202306212



-- Deletando o BD uvv e USER pedro.
        DROP DATABASE IF EXISTS uvv;
        DROP USER IF EXISTS pedro;

--Criação do user do BD, com permissão de criar BDs e usuários.
	
	CREATE USER pedro 
        WITH 
        CREATEDB 
        CREATEROLE 
        ENCRYPTED PASSWORD 'maia';

--Criação do BD uvv:
	
	CREATE DATABASE uvv 
        WITH 
        OWNER		pedro
	TEMPLATE	template0
        ENCODING        "UTF8"
        LC_COLLATE	'pt_BR.UTF-8'
        LC_CTYPE        'pt_BR.UTF-8'
        ALLOW_CONNECTIONS 	TRUE;
	
	COMMENT ON DATABASE uvv IS 'Banco de dados referente a assuntos da uvv.';

--Entrar no user pedro:
	\c 'dbname=uvv user=pedro password=maia';

--Criação do schema lojas:
	CREATE SCHEMA lojas AUTHORIZATION pedro;
--Configurar para usar permanentemente o esquema 'lojas':
	ALTER USER pedro
	SET SEARCH_PATH TO lojas, "$user", public;
	
	COMMENT ON SCHEMA lojas IS 'Esquema "lojas" do banco de dados "uvv", representa  as lojas associadas a uvv';


/*Criação das tabelas do esquema*/

/*Criação da tabela produtos,
suas colunas e chave primária:*/

	CREATE TABLE lojas.produtos (
                produto_id 			NUMERIC(38) NOT NULL,
                nome 				VARCHAR(255) NOT NULL,
                preco_unitario 			NUMERIC(10,2),
                detalhes 			BYTEA,
                imagem 				BYTEA,
                imagem_mime_type 		VARCHAR(512),
                imagem_arquivo 			VARCHAR(512),
                imagem_charset 			VARCHAR(512),
                imagem_ultima_atualizacao 	DATE,
                CONSTRAINT produtos_id_pk PRIMARY KEY (produto_id)
	);
--Comentários nos metadados da tabela:
	COMMENT ON TABLE lojas.produtos IS 'Tabela que listará dados dos produtos vendidos entre todas as lojas.';

	COMMENT ON COLUMN lojas.produtos.produto_id 	IS 'Número identificador de um produto. É único, positivo e inteiro. É a PK';
	COMMENT ON COLUMN lojas.produtos.nome 		IS 'Nome do produto. É unico';
	COMMENT ON COLUMN lojas.produtos.preco_unitario IS 'Preço da unidade de um produto. Não pode ser menor que 0.01';
	COMMENT ON COLUMN lojas.produtos.detalhes 	IS 'Detalhes do produto';
	COMMENT ON COLUMN lojas.produtos.imagem 	IS 'Imagem do produto';
	COMMENT ON COLUMN lojas.produtos.imagem_mime_type IS 'Informação MIME da imagem do produto';
	COMMENT ON COLUMN lojas.produtos.imagem_arquivo IS 'Nome arquivo da imagem do produto';
	COMMENT ON COLUMN lojas.produtos.imagem_charset IS 'Codificação da imagem do produto';
	COMMENT ON COLUMN lojas.produtos.imagem_ultima_atualizacao IS 'Ultima atualização na imagem do produto';

/*Criação da tabela lojas,
suas colunas e chave primária:*/

	CREATE TABLE lojas.lojas (
                loja_id 		NUMERIC(38) NOT NULL,
                nome 			VARCHAR(255) NOT NULL,
                endereco_web 		VARCHAR(100),
                endereco_fisico 	VARCHAR(512),
                latitude 		NUMERIC,
                longitude 		NUMERIC,
                logo 			BYTEA,
                logo_mime_type 		VARCHAR(512),
                logo_arquivo 		VARCHAR(512),
                logo_charset 		VARCHAR(512),
                logo_ultima_atualizacao DATE,
                CONSTRAINT loja_id_pk PRIMARY KEY (loja_id)
	);
--Comentários nos metadados da tabela:
	COMMENT ON TABLE lojas.lojas IS 'Tabela que listará dados das lojas';

	COMMENT ON COLUMN lojas.lojas.loja_id 			IS 'Número identificador de uma loja. É único, positivo e inteiro. É a PK';
	COMMENT ON COLUMN lojas.lojas.nome 			IS 'Nome da loja.';
	COMMENT ON COLUMN lojas.lojas.endereco_web 		IS 'Link do website da loja.';
	COMMENT ON COLUMN lojas.lojas.endereco_fisico 		IS 'Endereço geográfico da loja.';
	COMMENT ON COLUMN lojas.lojas.latitude 			IS 'Latitude do local da loja';
	COMMENT ON COLUMN lojas.lojas.longitude 		IS 'Longitude do local da looja';
	COMMENT ON COLUMN lojas.lojas.logo			IS 'Imagem da logo da loja';
	COMMENT ON COLUMN lojas.lojas.logo_mime_type 		IS 'Informação MIME da imagem da logo da loja';
	COMMENT ON COLUMN lojas.lojas.logo_arquivo 		IS 'Nome do arquivo da imagem da logo da loja';
	COMMENT ON COLUMN lojas.lojas.logo_charset 		IS 'Codificação da imagem da logo da loja';
	COMMENT ON COLUMN lojas.lojas.logo_ultima_atualizacao 	IS 'Ultima atualização na imagem da logo da loja';

/*Criação da tabela estoques,
suas colunas e chave primária:*/

	CREATE TABLE lojas.estoques (
                estoque_id 	NUMERIC(38) NOT NULL,
                loja_id 	NUMERIC(38) NOT NULL,
                produto_id 	NUMERIC(38) NOT NULL,
                quantidade 	NUMERIC(38) NOT NULL,
                CONSTRAINT estoque_id_pk PRIMARY KEY (estoque_id)
	);
--Comentários nos metadados da tabela:
	COMMENT ON TABLE lojas.estoques IS 'Tabela que listará dados dos estoques das lojas';

	COMMENT ON COLUMN lojas.estoques.estoque_id 	IS 'Número identificador de um estoque. É único, positivo e inteiro. É a PK';
	COMMENT ON COLUMN lojas.estoques.loja_id 	IS 'Loja a qual o estoque pertence';
	COMMENT ON COLUMN lojas.estoques.produto_id 	IS 'Produto do qual o estoque é feito';
	COMMENT ON COLUMN lojas.estoques.quantidade 	IS 'Quantidade do produto. Não pode ser negativa.';

/*Criação da tabela clientes,
suas colunas e chave primária:*/

	CREATE TABLE lojas.clientes (
                cliente_id 	NUMERIC(38) NOT NULL,
                email 		VARCHAR(255) NOT NULL,
                nome 		VARCHAR(255) NOT NULL,
                telefone1 	VARCHAR(20),
		telefone2 	VARCHAR(20),
                telefone3 	VARCHAR(20),
                
                CONSTRAINT clientes_id_pk PRIMARY KEY (cliente_id)
	);
--Comentários nos metadados da tabela:
	COMMENT ON TABLE lojas.clientes IS 'Tabela que listará dados dos clientes das lojas';

	COMMENT ON COLUMN lojas.clientes.cliente_id	 IS 'Número identificador de um cliente. É único, positivo e inteiro. É a PK';
	COMMENT ON COLUMN lojas.clientes.email		 IS 'Endereço de e-mail do cliente. Precisa conter o caractére "@".';
	COMMENT ON COLUMN lojas.clientes.nome		 IS 'Nome do cliente.';
	COMMENT ON COLUMN lojas.clientes.telefone1	 IS 'Telefone do cliente.';
	COMMENT ON COLUMN lojas.clientes.telefone2	 IS 'Segundo número de telefone do cliente.';
	COMMENT ON COLUMN lojas.clientes.telefone3	 IS 'Terceiro número de telefone do cliente.';

/*Criação da tabela envios,
suas colunas e chave primária:*/

	CREATE TABLE lojas.envios (
                envio_id 		NUMERIC(38) NOT NULL,
                cliente_id 		NUMERIC(38) NOT NULL,
                loja_id 		NUMERIC(38) NOT NULL,
                endereco_entrega 	VARCHAR(512) NOT NULL,
                status 			VARCHAR(15) NOT NULL,
                CONSTRAINT envio_id_pk PRIMARY KEY (envio_id)
	);
--Comentários nos metadados da tabela:
	COMMENT ON TABLE lojas.envios IS 'Tabela que listará dados dos envios das lojas';

	COMMENT ON COLUMN lojas.envios.envio_id	 	IS 'Número identificador de um envio. É único, positivo e inteiro. É a PK';
	COMMENT ON COLUMN lojas.envios.cliente_id	IS 'Identificador do cliente que efetuou o pedido.';
	COMMENT ON COLUMN lojas.envios.loja_id	 	IS 'Loja onde o pedido foi efetuado';
	COMMENT ON COLUMN lojas.envios.endereco_entrega	IS 'Endereço aonde deve ser concluído o envio';
	COMMENT ON COLUMN lojas.envios.status	 	IS 'Estado do envio.';

/*Criação da tabela pedidos,
suas colunas e chave primária:*/

	CREATE TABLE lojas.pedidos (
                pedido_id 	NUMERIC(38) NOT NULL,
                data_hora 	TIMESTAMP NOT NULL,
                cliente_id 	NUMERIC(38) NOT NULL,
                status 		VARCHAR(15) NOT NULL,
                loja_id 	NUMERIC(38) NOT NULL,
                CONSTRAINT pedido_id_pk PRIMARY KEY (pedido_id)
	);
--Comentários nos metadados da tabela:
	COMMENT ON TABLE lojas.pedidos IS 'Tabela que listará dados dos pedidos';

	COMMENT ON COLUMN lojas.pedidos.pedido_id 	IS 'Número identificador de um pedido. É único, positivo e inteiro. É a PK';
	COMMENT ON COLUMN lojas.pedidos.data_hora 	IS 'Data e hora que o pedido foi efetuado.';
	COMMENT ON COLUMN lojas.pedidos.cliente_id 	IS 'Identificador do cliente que efetuou o pedido.';
	COMMENT ON COLUMN lojas.pedidos.status	 	IS 'Estado do pedido';
	COMMENT ON COLUMN lojas.pedidos.loja_id 	IS 'Loja onde o pedido foi efetuado.';

/*Criação da tabela pedidos_itens,
suas colunas e chave primária:*/

	CREATE TABLE lojas.pedidos_itens (
                pedido_id 	NUMERIC(38) NOT NULL,
                produto_id 	NUMERIC(38) NOT NULL,
                numero_da_linha NUMERIC(38) NOT NULL,
                preco_unitario 	NUMERIC(10,2) NOT NULL,
                quantidade 	NUMERIC(38) NOT NULL,
                envio_id 	NUMERIC(38),
                CONSTRAINT pedidos_itens_pk PRIMARY KEY (pedido_id, produto_id)
	);
--Comentários nos metadados da tabela:
	COMMENT ON TABLE lojas.pedidos_itens IS 'Tabela que listará dados dos itens dos pedidos';

	COMMENT ON COLUMN lojas.pedidos_itens.pedido_id 	IS 'Identificador de um pedido. É único, positivo e inteiro. É a PK';
	COMMENT ON COLUMN lojas.pedidos_itens.produto_id	IS 'Identificador de um produto. É único, positivo e inteiro. É a PK';
	COMMENT ON COLUMN lojas.pedidos_itens.numero_da_linha 	IS 'Ordem dos produtos no pedido.';
	COMMENT ON COLUMN lojas.pedidos_itens.preco_unitario 	IS 'Preço da unidade de um produto. Não pode ser menor que 0.01.';
	COMMENT ON COLUMN lojas.pedidos_itens.quantidade 	IS 'Quantidade do produto. Não pode ser negativa.';
	COMMENT ON COLUMN lojas.pedidos_itens.envio_id	 	IS 'Identificador de um envio. É único, positivo e inteiro.';


/*Criando relacionamentos entre as tabelas
*/

--Relacionando a tabela 'pedidos_itens' com a tabela 'produtos'
	ALTER TABLE lojas.pedidos_itens 
	ADD CONSTRAINT produtos_pedidos_itens_fk
	FOREIGN KEY (produto_id)
	REFERENCES lojas.produtos (produto_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;

--Relacionando a tabela 'estoques' com a tabela 'produtos'
	ALTER TABLE lojas.estoques ADD CONSTRAINT produtos_estoques_fk
	FOREIGN KEY (produto_id)
	REFERENCES lojas.produtos (produto_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;

--Relacionando a tabela 'pedidos' com a tabela 'lojas'
	ALTER TABLE lojas.pedidos ADD CONSTRAINT lojas_pedidos_fk	
	FOREIGN KEY (loja_id)
	REFERENCES lojas.lojas (loja_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;

--Relacionando a tabela 'envios' com a tabela 'lojas'
	ALTER TABLE lojas.envios ADD CONSTRAINT lojas_envios_fk
	FOREIGN KEY (loja_id)
	REFERENCES lojas.lojas (loja_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;

--Relacionando a tabela 'estoques' com a tabela 'lojas'
	ALTER TABLE lojas.estoques ADD CONSTRAINT lojas_estoques_fk
	FOREIGN KEY (loja_id)
	REFERENCES lojas.lojas (loja_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;

--Relacionando a tabela 'pedidos' com a tabela 'clientes'
	ALTER TABLE lojas.pedidos ADD CONSTRAINT clientes_pedidos_fk
	FOREIGN KEY (cliente_id)
	REFERENCES lojas.clientes (cliente_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;

--Relacionando a tabela 'envios' com a tabela 'clientes'
	ALTER TABLE lojas.envios ADD CONSTRAINT clientes_envios_fk
	FOREIGN KEY (cliente_id)
	REFERENCES lojas.clientes (cliente_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;

--Relacionando a tabela 'pedidos_itens' com a tabela 'envios'
	ALTER TABLE lojas.pedidos_itens ADD CONSTRAINT envios_pedidos_itens_fk
	FOREIGN KEY (envio_id)
	REFERENCES lojas.envios (envio_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;

--Relacionando a tabela 'pedidos_itens' com a tabela 'pedidos'
	ALTER TABLE lojas.pedidos_itens ADD CONSTRAINT pedidos_pedidos_itens_fk
	FOREIGN KEY (pedido_id)
	REFERENCES lojas.pedidos (pedido_id)
	ON DELETE NO ACTION
	ON UPDATE NO ACTION
	NOT DEFERRABLE;


/*Criando diversas restrições para as tabelas*/

/*Restrições para tornar os identificadores únicos:*/
	ALTER TABLE lojas.clientes
	ADD CONSTRAINT cliente_unico UNIQUE (cliente_id);
	
	ALTER TABLE lojas.pedidos
	ADD CONSTRAINT pedido_unico UNIQUE (pedido_id);

	ALTER TABLE lojas.lojas
	ADD CONSTRAINT loja_unico UNIQUE (loja_id);

	ALTER TABLE lojas.produtos
	ADD CONSTRAINT produto_unico UNIQUE (produto_id);

	ALTER TABLE lojas.estoques
	ADD CONSTRAINT estoque_unico UNIQUE (estoque_id);

	ALTER TABLE lojas.envios
	ADD CONSTRAINT envio_unico UNIQUE (envio_id);

--Restrição: Duas lojas não podem ter o mesmo endereço físico:
	ALTER TABLE lojas.lojas
	ADD CONSTRAINT endereco_unico UNIQUE (endereco_fisico);

--Restrição: Dois produtos não podem ter o mesmo nome:
	ALTER TABLE lojas.produtos
	ADD CONSTRAINT nome_produnico UNIQUE (nome);

--Restrição: Qualquer e-mail inserido precisa ter o caractére '@':
	ALTER TABLE lojas.clientes
	ADD CONSTRAINT email_correto CHECK (email LIKE '%@%');

--Restrição: pelo menos um dos dois endereços precisa ser preenchido:
	ALTER TABLE lojas.lojas
	ADD CONSTRAINT endereco_min CHECK (endereco_web IS NOT NULL OR endereco_fisico IS NOT NULL);

/*Restrições para tornar os identificadores inteiros positivos:*/
	ALTER TABLE lojas.clientes
	ADD CONSTRAINT cliente_id CHECK (cliente_id > 0 AND cliente_id::integer = cliente_id);

	ALTER TABLE lojas.produtos
	ADD CONSTRAINT produto_id CHECK (produto_id > 0 AND produto_id::integer = produto_id);

	ALTER TABLE lojas.pedidos
	ADD CONSTRAINT pedido_id CHECK (pedido_id > 0 AND pedido_id::integer = pedido_id);

	ALTER TABLE lojas.lojas
	ADD CONSTRAINT loja_id CHECK (loja_id > 0 AND loja_id::integer = loja_id);

	ALTER TABLE lojas.estoques
	ADD CONSTRAINT estoque_id CHECK (estoque_id > 0 AND estoque_id::integer = estoque_id);

	ALTER TABLE lojas.envios
	ADD CONSTRAINT envio_id CHECK (envio_id > 0 AND envio_id::integer = envio_id);


/*Restrições para que a quantidade não seja negativa*/
	ALTER TABLE lojas.estoques
	ADD CONSTRAINT qnt_min CHECK (quantidade >= 0);

	ALTER TABLE lojas.pedidos_itens
	ADD CONSTRAINT qnt_minpedido CHECK (quantidade >= 0);

/*Restrições para que o preço de um item não seja 0 ou negativo:*/
	ALTER TABLE lojas.pedidos_itens
	ADD CONSTRAINT preco_proditem CHECK (preco_unitario > 0);

	ALTER TABLE lojas.produtos
	ADD CONSTRAINT preco_prod CHECK (preco_unitario > 0);

/*Restrições de estado de pedido e envio:*/
	ALTER TABLE lojas.pedidos
	ADD CONSTRAINT status_pedidos CHECK (status IN ('CANCELADO', 'COMPLETO', 'ABERTO', 'PAGO', 'REEMBOLSADO', 'ENVIADO'));

	ALTER TABLE lojas.envios
	ADD CONSTRAINT status_envios CHECK (status IN ('CRIADO', 'ENVIADO', 'TRANSITO', 'ENTREGUE'));
