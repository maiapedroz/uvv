using MySql.Data.MySqlClient;
using System;

public class DBConnection
{
    private static DBConnection instance;
    private MySqlConnection connection;

    private DBConnection()
    {
        string connectionString = "server=localhost;" + "port=3307;" +
            "user=root;password=123456;database=livraria";
        connection = new MySqlConnection(connectionString);
    }

    public static DBConnection GetInstance()
    {
        if (instance == null)
        {
            instance = new DBConnection();
        }
        return instance;
    }

    public MySqlConnection GetConnection()
    {
        return connection;
    }
}
