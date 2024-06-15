#include <iostream>
#include <string>
#include <algorithm>

std::string add(std::string lhs, std::string rhs) {
    std::string::size_type length = std::max(lhs.size(), rhs.size());
    int carry = 0;
    int sum_col;  // sum of two digits in the same column
    std::string result;

    // pad the beginning of the shorter string with zeros
    while (lhs.size() < length) 
      lhs.insert(0,"0");
            
    while (rhs.size() < length) 
      rhs.insert(0,"0");

    // build result string from right to left
    for (int i = length-1; i >= 0; i--) {
      sum_col = (lhs[i]-'0') + (rhs[i]-'0') + carry;
      carry = sum_col/10;
      result.insert(0,std::to_string(sum_col % 10));
    }

    if (carry)
      result.insert(0,std::to_string(carry));
    
    // remove leading zeros
    return result.erase(0, std::min(result.find_first_not_of('0'), result.size()-1));
}

std::string subtract(std::string lhs, std::string rhs) {
    std::string::size_type length = std::max(lhs.size(), rhs.size());
    int diff;
    std::string result;

    while (lhs.size() < length) 
      lhs.insert(0,"0");
            
    while (rhs.size() < length) 
      rhs.insert(0,"0");

    for (int i = length-1; i >= 0; i--) {
        diff = (lhs[i]-'0') - (rhs[i]-'0');
        if (diff >= 0)
            result.insert(0, std::to_string(diff));
        else {

            // borrow from the previous column
            int j = i - 1;
            while (j >= 0) {
                lhs[j] = ((lhs[j]-'0') - 1) % 10 + '0';
                if (lhs[j] != '9') 
                    break;
                else 
                    j--;
            }
            result.insert(0, std::to_string(diff+10));
        }

    }

    return result.erase(0, std::min(result.find_first_not_of('0'), result.size()-1));
}

std::string multiply(std::string lhs, std::string rhs) {
    std::string::size_type length = std::max(lhs.size(), rhs.size());

    while (lhs.size() < length) 
      lhs.insert(0,"0");

    while (rhs.size() < length) 
      rhs.insert(0,"0");

    if (length == 1)
        return std::to_string((lhs[0]-'0')*(rhs[0]-'0'));

    std::string lhs0 = lhs.substr(0,length/2);
    std::string lhs1 = lhs.substr(length/2,length-length/2);
    std::string rhs0 = rhs.substr(0,length/2);
    std::string rhs1 = rhs.substr(length/2,length-length/2);

    std::string p0 = multiply(lhs0,rhs0);
    std::string p1 = multiply(lhs1,rhs1);
    std::string p2 = multiply(add(lhs0,lhs1),add(rhs0,rhs1));
    std::string p3 = subtract(p2,add(p0,p1));

    for (std::string::size_type i = 0; i < 2*(length-length/2); i++)
        p0.append("0");
    for (std::string::size_type i = 0; i < length-length/2; i++)
        p3.append("0");
        
    return add(add(p0,p1),p3);
}

int main() {
    std::string a = "876415926535897932384626433832795028841971693993751867970582097494459";
    std::string b = "121828182845904523536028747135266249775724709369995957496696762741212";
    std::cout << "Hasil perkalian dari \n" << a << "\n dan \n" << b << "\n adalah: " << std::endl;
    std::cout << multiply(a, b) << std::endl;

    

    return 0;
}