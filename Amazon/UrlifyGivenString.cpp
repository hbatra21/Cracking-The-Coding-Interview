int replaceSpaces(string str) 
{ 
    int space_count = 0, i; 
    for (i = 0; str[i]; i++) 
        if (str[i] == ' ') 
            space_count++; 
    while (str[i-1] == ' ') { 
       space_count--; 
       i--; 
    }
    int new_length = i + space_count * 2 + 1; 
    if (new_length > MAX) 
        return -1; 
    int index = new_length - 1; 
    str[index--] = '\0'; 
    for (int j=i-1; j>=0; j--) 
    { 
       if (str[j] == ' ') 
        { 
            str[index] = '0'; 
            str[index - 1] = '2'; 
            str[index - 2] = '%'; 
            index = index - 3; 
        } 
        else
        { 
            str[index] = str[j]; 
            index--; 
        } 
    } 
    return new_length; 
} 
