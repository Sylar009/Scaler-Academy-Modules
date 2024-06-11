package doublechecklock;

public class DoubleCheckDBConn {
    private static DoubleCheckDBConn dbConnection = null;
    private DoubleCheckDBConn() {
    }

    /**
     * This will work in multi threaded ENV.
     *
     *
     * @return
     */
    public static DoubleCheckDBConn createInstance(){
            if(dbConnection ==null){
                synchronized (DoubleCheckDBConn.class){
                    if(dbConnection ==null){
                        dbConnection = new DoubleCheckDBConn();
                    }
                }
            }
            return dbConnection;
    }


    /**
     * 1. Identify what problems in DCL
     * 2. ENUM BASED SINGLETON CLASS
     */
}