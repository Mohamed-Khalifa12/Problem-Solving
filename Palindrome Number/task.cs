public class Solution {
    public bool IsPalindrome(int x) {
        string num1 = Convert.ToString(x);
        string num2 = Reverse(num1);
        if(num1 == num2)
            return true;
        return false;
    }

    public string Reverse(string Input) 
    { 
        char[] charArray = Input.ToCharArray(); 
        string reversedString = String.Empty; 
        for(int i = charArray.Length - 1; i > -1; i--) 
        { 
            reversedString += charArray[i]; 
        }
        return reversedString;
    } 
}