import static java.lang.System.*;
public class exit1 {
public static final int EXIT_SUCCESS = 0;
   public static final int EXIT_FAILURE = 1;
   public static int exit_status = EXIT_SUCCESS;
   
   public static void main(String[] args) {
      System.err.println("EXIT 1");
      exit_status = EXIT_FAILURE;
      exit(exit_status);
      }
}
