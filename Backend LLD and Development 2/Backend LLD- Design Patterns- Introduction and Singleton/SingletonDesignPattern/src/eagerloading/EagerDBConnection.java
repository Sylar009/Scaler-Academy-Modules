package eagerloading;

public class EagerDBConnection {
    private EagerDBConnection() {
    }

    private static EagerDBConnection dbConnection = new EagerDBConnection();

    /**
     * PROBLEM: many classes on app start could lead to increase in app start time.
     * @return
     */
    public static EagerDBConnection createInstance() {
        return dbConnection;
    }
}
