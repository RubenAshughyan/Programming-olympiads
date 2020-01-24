
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Abbreviation {


    static String process(String abbreviation) {
        StringTokenizer st = new StringTokenizer(abbreviation);
        String abbr = "";

        while (st.hasMoreTokens()) {
            String token = st.nextToken();
            abbr += token.charAt(0);
        }
        return abbr + String.format(" (%s)", abbreviation);
    }

    public static void main(String[] strings) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new File("src/file.txt"));


        while (sc.hasNextLine()) {
            TreeSet<String> treeSet = new TreeSet<>();
            String line = sc.nextLine()+" ";
            Pattern pattern = Pattern.compile("\\b(([a-Z][a-z]+\\s)+[a-Z][a-z]+)[\\s|,|\\.]");
            Matcher matcher = pattern.matcher(line);

            boolean replaced = false;
            while (matcher.find()) {
                String abbreviation = matcher.group(1);
                if(!treeSet.contains(abbreviation)) {
                    line = line.replace(abbreviation,  process(abbreviation));
                    treeSet.add(abbreviation);
                }
                replaced = true;
            }
            System.out.println(line.substring(0,line.length()-1));



        }

    }


}
