using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {

        //private string connectionString = "server=localhost;" + "port=3307;" +
        //"user=root;password=123456;database=livraria";

        private MySqlConnection connection;

        public Form1()
        {
            
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)  // READ
        {
            connection = DBConnection.GetInstance().GetConnection();
            string query = "SELECT title AS Título, author AS Autor, publication_date AS Publicação, isbn AS ISBN, quantity AS Estoque\r\nFROM books;";
            MySqlCommand command = new MySqlCommand(query, connection);
            connection.Open();

            // Preencher um DataTable com os resultados
            MySqlDataAdapter adapter = new MySqlDataAdapter(command);
            DataTable table = new DataTable();
            adapter.Fill(table);

            // Definir o DataSource do DataGridView
            dataGridView1.DataSource = table;
            connection.Close();
        }

        private void btnCreate_Click(object sender, EventArgs e)    // CREATE
        {
            connection = DBConnection.GetInstance().GetConnection();
            connection.Open();
            string query = "INSERT INTO books(title, author, publication_date, isbn, quantity) VALUES" +
            "(@title, @author, @publication_date, @isbn, @quantity)";
            MySqlCommand command = new MySqlCommand(query, connection);
            command.Parameters.AddWithValue("@title", txtTitle.Text);
            command.Parameters.AddWithValue("@author", txtDesc.Text);
            command.Parameters.AddWithValue("@publication_date", DateTime.Now);
            command.Parameters.AddWithValue("@isbn", txtISBN.Text);
            command.Parameters.AddWithValue("@quantity", txtStock.Text);

            command.ExecuteNonQuery();
            connection.Close();
            MessageBox.Show("Product Created Successfully!");
            txtTitle.Text = "";
            txtDesc.Text = "";
            txtISBN.Text = "";
            txtStock.Text = "";
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void btnUpdate_Click(object sender, EventArgs e)    // Update
        {
            // Criando 3 Labels
            Label lblttTEMP = new Label();
            lblttTEMP.Text = "Título:";
            lblttTEMP.Location = new Point(570, 222);
            lblttTEMP.AutoSize = true;
            this.Controls.Add(lblttTEMP);

            Label lblAuTemp = new Label();
            lblAuTemp.Text = "Autor:";
            lblAuTemp.Location = new Point(570, 257);
            lblAuTemp.AutoSize = true;
            this.Controls.Add(lblAuTemp);

            Label lblQtTemp = new Label();
            lblQtTemp.Text = "Estoque";
            lblQtTemp.Location = new Point(570, 292);
            lblQtTemp.AutoSize = true;  
            this.Controls.Add(lblQtTemp);

            // Criando 3 TextBoxes
            TextBox txtTTtemp = new TextBox();
            txtTTtemp.Location = new Point(625, 217);
            this.Controls.Add(txtTTtemp);

            TextBox txtAuTemp = new TextBox();
            txtAuTemp.Location = new Point(625, 252);
            this.Controls.Add(txtAuTemp);

            TextBox txtQtTemp = new TextBox();
            txtQtTemp.Location = new Point(625, 287);
            this.Controls.Add(txtQtTemp);

            // Criando o botão
            Button bttUpdate = new Button();
            bttUpdate.Text = "Atualizar";
            bttUpdate.Location = new Point(601, 330);

            connection = DBConnection.GetInstance().GetConnection();
            connection.Open();
            // Definir o evento de clique
            bttUpdate.Click += (s, ev) =>
            {
                // Verificar se os campos estão preenchidos
                if (!string.IsNullOrEmpty(txtTTtemp.Text) || !string.IsNullOrEmpty(txtAuTemp.Text) || !string.IsNullOrEmpty(txtQtTemp.Text))
                {
                    // Obter valores dos campos
                    string title = txtTTtemp.Text.Trim();
                    string author = txtAuTemp.Text.Trim();
                    string quantityText = txtQtTemp.Text.Trim();
                    int? quantity = null;

                    // Tentar converter o valor de quantidade para inteiro
                    if (!string.IsNullOrEmpty(quantityText) && int.TryParse(quantityText, out int qty))
                    {
                        quantity = qty;
                    }

                    // Construir a consulta UPDATE
                    string query = "UPDATE books SET ";

                    // Adicionar colunas para atualizar com base nos campos preenchidos
                    List<string> setClauses = new List<string>();

                    if (!string.IsNullOrEmpty(title))
                    {
                        setClauses.Add($"title = '{title}'");
                    }

                    if (!string.IsNullOrEmpty(author))
                    {
                        setClauses.Add($"author = '{author}'");
                    }

                    if (quantity.HasValue)
                    {
                        setClauses.Add($"quantity = {quantity}");
                    }

                    // Se houver campos para atualizar, continuar
                    if (setClauses.Count > 0)
                    {
                        query += string.Join(", ", setClauses) + " WHERE isbn = @isbn";

                        // Conectar ao banco de dados e executar o comando
                        MySqlCommand command = new MySqlCommand(query, connection);
                        command.Parameters.AddWithValue("@isbn", txtISBNUD.Text); // Substitua bookId pelo ID do livro que você deseja alterar

                        connection.Open();
                        int rowsAffected = command.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Dados atualizados com sucesso!");
                            connection.Close();
                            this.Controls.Remove(txtTTtemp);
                            this.Controls.Remove(txtAuTemp);
                            this.Controls.Remove(txtQtTemp);
                            this.Controls.Remove(lblttTEMP);
                            this.Controls.Remove(lblAuTemp);
                            this.Controls.Remove(lblQtTemp);
                            this.Controls.Remove(bttUpdate);
                            bttUpdate.Dispose();

                            txtISBNUD.Text = "";
                        }
                        else
                        {
                            MessageBox.Show("Nenhum dado foi atualizado.");
                        }
                    }
                    else
                    {
                        MessageBox.Show("Por favor, preencha ao menos um campo.");
                    }
                }
                else
                {
                    MessageBox.Show("Por favor, preencha ao menos um campo.");
                }

                
            };

            // Adicionar o botão ao formulário
            this.Controls.Add(bttUpdate);


            string query2 = "SELECT title AS Título, author AS Autor, publication_date AS Publicação, isbn AS ISBN, quantity AS Estoque\r\nFROM books\r\nWHERE isbn = @isbn;";
            MySqlCommand command2 = new MySqlCommand(query2, connection);
            command2.Parameters.AddWithValue("@isbn", txtISBNUD.Text);
            

            // Preencher um DataTable com os resultados
            MySqlDataAdapter adapter = new MySqlDataAdapter(command2);
            DataTable table = new DataTable();
            adapter.Fill(table);

            // Definir o DataSource do DataGridView
            dataGridView1.DataSource = table;
            connection.Close();
        }

        private void btnDelete_Click(object sender, EventArgs e)    // Delete
        {
            connection = DBConnection.GetInstance().GetConnection();
            string query = "DELETE FROM books\r\nWHERE isbn = @isbn;";
            MySqlCommand command = new MySqlCommand(query, connection);
            command.Parameters.AddWithValue("@isbn", txtISBNUD.Text);
            connection.Open();
            command.ExecuteNonQuery();
            MessageBox.Show("Livro deletado!");
            txtISBNUD.Text = "";
            connection.Close();
            
        }
    }
}
