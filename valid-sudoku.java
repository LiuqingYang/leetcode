// need modify to static class and submit to leetcode

class Solution {
    public static boolean isValidSudoku(char[][] board) {
        int i, j;
        // valid line
        for (i = 0; i < 9; i++) {
            int bitset = 0;
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int bitfield = (1 << (board[i][j] - '0'));
                    if ((bitset & bitfield) != 0) return false;
                    bitset = bitset | bitfield;
                }
            }
        }
        
        // valid row
        for (j = 0; j < 9; j++) {
            int bitset = 0;
            for (i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    int bitfield = (1 << (board[i][j] - '0'));
                    if ((bitset & bitfield) != 0) return false;
                    bitset = bitset | bitfield;
                }
            }
        }
        
        // valid block
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                int bitset = 0;
                int x = a * 3;
                int y = b * 3;

                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (board[x + i][y +j] != '.') {
                            int bitfield = (1 << (board[x + i][y +j] - '0'));
                            if ((bitset & bitfield) != 0) return false;
                            bitset = bitset | bitfield;
                        }
                    }
                }
            }
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        String str0 = ".87654321";
        String str1 = "2........";
        String str2 = "3........";
        String str3 = "4........";
        String str4 = "5........";
        String str5 = "6........";
        String str6 = "7........";
        String str7 = "8........";
        String str8 = "9........";
        char[][] board;
        boolean ret;
        
        board = new char[9][];
        board[0] = str0.toCharArray();
        board[1] = str1.toCharArray();
        board[2] = str2.toCharArray();
        board[3] = str3.toCharArray();
        board[4] = str4.toCharArray();
        board[5] = str5.toCharArray();
        board[6] = str6.toCharArray();
        board[7] = str7.toCharArray();
        board[8] = str8.toCharArray();
        
        ret = isValidSudoku(board);
        
        System.out.println("return: " + ret);
    }
}
