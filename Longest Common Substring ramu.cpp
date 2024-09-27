#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Function to find the longest common substring
std::string longestCommonSubstring(const std::string& s1, const std::string& s2) {
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int>> table(n + 1, std::vector<int>(m + 1, 0));
    
    int maxLength = 0;  // To store the length of the longest common substring
    int endIdx = 0;     // To store the ending index of the longest common substring
    
    // Building the lookup table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                
                // Check if we found a new max length
                if (table[i][j] > maxLength) {
                    maxLength = table[i][j];
                    endIdx = i - 1;
                }
            } else {
                table[i][j] = 0;  // Reset if characters don't match
            }
        }
    }
    
    // Output the table for visual representation
    std::cout << "\nDetailed Lookup Table:\n";
    
    // Print the top header row
    std::cout << "    "; 
    for (int j = 0; j < m; ++j) {
        std::cout << s2[j] << " ";
    }
    std::cout << "\n";
    
    // Print the lookup table with row headers
    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            std::cout << "  ";  /
        } else {
            std::cout << s1[i - 1] << " "; // Row header for string s1
        }
        
        for (int j = 0; j <= m; ++j) {
            std::cout << table[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    // Return the longest common substring using the end index and max length
    if (maxLength == 0) return "";  // If there's no common substring
    return s1.substr(endIdx - maxLength + 1, maxLength);
}

int main() {
    std::string str1, str2;
    
    // Taking input strings from the user
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    
    std::cout << "Enter the second string: ";
    std::cin >> str2;
    
    // Ensure both strings are of identical length
    if (str1.length() != str2.length()) {
        std::cout << "Error: Strings must be of the same length.\n";
        return 1;
    }

    // Displaying the input strings
    std::cout << "String 1: " << str1 << "\n";
    std::cout << "String 2: " << str2 << "\n";
    
    std::string result = longestCommonSubstring(str1, str2);
    
    if (!result.empty()) {
        std::cout << "\nLongest Common Substring: " << result << "\n";
        std::cout << "Length: " << result.length() << "\n";
    } else {
        std::cout << "No Common Substring found.\n";
    }
    
    return 0;
}
