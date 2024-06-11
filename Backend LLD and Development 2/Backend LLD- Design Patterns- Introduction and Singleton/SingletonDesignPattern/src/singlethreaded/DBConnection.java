package singlethreaded;

public class DBConnection {
    private static DBConnection dbConnection = null;

    private DBConnection() {
    }

    public static DBConnection createInstance(){
        if(dbConnection == null){
            dbConnection = new DBConnection();
        }
        return dbConnection;
    }
}