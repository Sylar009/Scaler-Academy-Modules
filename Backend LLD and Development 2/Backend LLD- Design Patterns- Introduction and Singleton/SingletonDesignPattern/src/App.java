

import eagerloading.EagerDBConnection;
import singlethreaded.DBConnection;

public class App {
    public static void main(String[] args) throws Exception {
        DBConnection one = DBConnection.createInstance();
        DBConnection two = DBConnection.createInstance();

        System.out.println("FIRST OBJECT DBConnection " + one);
        System.out.println("SECOND OBJECT DBConnection " + two);

        EagerDBConnection eagerDBConnection = EagerDBConnection.createInstance();
        EagerDBConnection eagerDBConnection2 = EagerDBConnection.createInstance();

        System.out.println("FIRST OBJECT" + eagerDBConnection);
        System.out.println("SECOND OBJECT" + eagerDBConnection2);
    }
}
