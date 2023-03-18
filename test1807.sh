




if [ $# -eq 0 ]; then
    echo "Usage: phone searchfor [...searchfor]"
    echo "(You didn't tell me what you want to search for.)"
    exit 1
else
    ## 将所有参数合并成正则表达式
    or_input=$(echo "$@" | tr ' ' '|')
    and_input=$(echo "$@" | tr ' ' '\n' | sort | uniq | sed 's/.*/&/' | tr '\n' '.*')

    ## 使用 egrep 提取数据，并使用 awk 格式输出
    or_result=$(cat mydata | egrep -i "($or_input)" | awk 'BEGIN {FS = "|"}; 
    {print "---------------->\nname: " $1 "\naddress: " $2 "\nphone: " $3"\n<----------------"}')
    
    and_result=$(cat mydata | egrep -i "$and_input" | awk 'BEGIN {FS = "|"}; 
    {print "---------------->\nname: " $1 "\naddress: " $2 "\nphone: " $3"\n<----------------"}')

    echo "출력 (or 형식)"
    echo "$or_result"
    echo "출력 (and 형식)"
    echo "$and_result"
fi


