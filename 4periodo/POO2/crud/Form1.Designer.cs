namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.txtTitle = new System.Windows.Forms.TextBox();
            this.lblTitle = new System.Windows.Forms.Label();
            this.txtDesc = new System.Windows.Forms.TextBox();
            this.txtISBN = new System.Windows.Forms.TextBox();
            this.lblAuth = new System.Windows.Forms.Label();
            this.lblISBN = new System.Windows.Forms.Label();
            this.lblStock = new System.Windows.Forms.Label();
            this.txtStock = new System.Windows.Forms.TextBox();
            this.btnCreate = new System.Windows.Forms.Button();
            this.btnRead = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.isbnUD = new System.Windows.Forms.Label();
            this.txtISBNUD = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(19, 208);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(546, 201);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // txtTitle
            // 
            this.txtTitle.Location = new System.Drawing.Point(61, 26);
            this.txtTitle.Name = "txtTitle";
            this.txtTitle.Size = new System.Drawing.Size(224, 20);
            this.txtTitle.TabIndex = 1;
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Location = new System.Drawing.Point(25, 29);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(36, 13);
            this.lblTitle.TabIndex = 2;
            this.lblTitle.Text = "Titulo:";
            this.lblTitle.Click += new System.EventHandler(this.label1_Click);
            // 
            // txtDesc
            // 
            this.txtDesc.Location = new System.Drawing.Point(61, 61);
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.Size = new System.Drawing.Size(224, 20);
            this.txtDesc.TabIndex = 3;
            // 
            // txtISBN
            // 
            this.txtISBN.Location = new System.Drawing.Point(61, 94);
            this.txtISBN.Name = "txtISBN";
            this.txtISBN.Size = new System.Drawing.Size(224, 20);
            this.txtISBN.TabIndex = 4;
            // 
            // lblAuth
            // 
            this.lblAuth.AutoSize = true;
            this.lblAuth.Location = new System.Drawing.Point(20, 64);
            this.lblAuth.Name = "lblAuth";
            this.lblAuth.Size = new System.Drawing.Size(35, 13);
            this.lblAuth.TabIndex = 5;
            this.lblAuth.Text = "Autor:";
            this.lblAuth.Click += new System.EventHandler(this.label1_Click_1);
            // 
            // lblISBN
            // 
            this.lblISBN.AutoSize = true;
            this.lblISBN.Location = new System.Drawing.Point(21, 97);
            this.lblISBN.Name = "lblISBN";
            this.lblISBN.Size = new System.Drawing.Size(35, 13);
            this.lblISBN.TabIndex = 6;
            this.lblISBN.Text = "ISBN:";
            // 
            // lblStock
            // 
            this.lblStock.AutoSize = true;
            this.lblStock.Location = new System.Drawing.Point(12, 132);
            this.lblStock.Name = "lblStock";
            this.lblStock.Size = new System.Drawing.Size(49, 13);
            this.lblStock.TabIndex = 8;
            this.lblStock.Text = "Estoque:";
            this.lblStock.Click += new System.EventHandler(this.label3_Click);
            // 
            // txtStock
            // 
            this.txtStock.Location = new System.Drawing.Point(61, 129);
            this.txtStock.Name = "txtStock";
            this.txtStock.Size = new System.Drawing.Size(224, 20);
            this.txtStock.TabIndex = 7;
            // 
            // btnCreate
            // 
            this.btnCreate.Location = new System.Drawing.Point(308, 19);
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.Size = new System.Drawing.Size(75, 130);
            this.btnCreate.TabIndex = 9;
            this.btnCreate.Text = "Novo";
            this.btnCreate.UseVisualStyleBackColor = true;
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            // 
            // btnRead
            // 
            this.btnRead.Location = new System.Drawing.Point(446, 23);
            this.btnRead.Name = "btnRead";
            this.btnRead.Size = new System.Drawing.Size(77, 122);
            this.btnRead.TabIndex = 10;
            this.btnRead.Text = "Todos os livros";
            this.btnRead.UseVisualStyleBackColor = true;
            this.btnRead.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(601, 73);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(75, 23);
            this.btnUpdate.TabIndex = 11;
            this.btnUpdate.Text = "Alterar";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(704, 73);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(75, 23);
            this.btnDelete.TabIndex = 12;
            this.btnDelete.Text = "Remover";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // isbnUD
            // 
            this.isbnUD.AutoSize = true;
            this.isbnUD.Location = new System.Drawing.Point(561, 50);
            this.isbnUD.Name = "isbnUD";
            this.isbnUD.Size = new System.Drawing.Size(35, 13);
            this.isbnUD.TabIndex = 14;
            this.isbnUD.Text = "ISBN:";
            // 
            // txtISBNUD
            // 
            this.txtISBNUD.Location = new System.Drawing.Point(601, 47);
            this.txtISBNUD.Name = "txtISBNUD";
            this.txtISBNUD.Size = new System.Drawing.Size(188, 20);
            this.txtISBNUD.TabIndex = 13;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.isbnUD);
            this.Controls.Add(this.txtISBNUD);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnUpdate);
            this.Controls.Add(this.btnRead);
            this.Controls.Add(this.btnCreate);
            this.Controls.Add(this.lblStock);
            this.Controls.Add(this.txtStock);
            this.Controls.Add(this.lblISBN);
            this.Controls.Add(this.lblAuth);
            this.Controls.Add(this.txtISBN);
            this.Controls.Add(this.txtDesc);
            this.Controls.Add(this.lblTitle);
            this.Controls.Add(this.txtTitle);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox txtTitle;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.TextBox txtDesc;
        private System.Windows.Forms.TextBox txtISBN;
        private System.Windows.Forms.Label lblAuth;
        private System.Windows.Forms.Label lblISBN;
        private System.Windows.Forms.Label lblStock;
        private System.Windows.Forms.TextBox txtStock;
        private System.Windows.Forms.Button btnCreate;
        private System.Windows.Forms.Button btnRead;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Label isbnUD;
        private System.Windows.Forms.TextBox txtISBNUD;
    }
}

