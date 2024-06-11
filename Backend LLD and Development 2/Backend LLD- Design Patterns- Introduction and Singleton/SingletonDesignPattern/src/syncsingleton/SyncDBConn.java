package syncsingleton;

import singlethreaded.DBConnection;

public class SyncDBConn {
    private static SyncDBConn dbConnection = null;
    private SyncDBConn() {
    }

    /**
     * This will work in multi threaded ENV.
     * PROBLEMS -- because I am taking lock on complete method, it will hamper performace.
     *
     * @return
     */
    public static synchronized SyncDBConn createInstance(){
        if(dbConnection == null){
            dbConnection = new SyncDBConn();
        }
        return dbConnection;
    }
}