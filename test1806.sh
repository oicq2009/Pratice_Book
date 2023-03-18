


# AND
if [ $# -eq 0 ]; then
    echo "Usage: phone searchfor [...searchfor]"
    echo "(You didn't tell me what you want to search for.)"
    exit 1
else
    input=$(echo "$@" | tr ' ' '\n' | sort | uniq | sed 's/.*/&/' | tr '\n' '.*')
    cat mydata | egrep -i "$input" | awk 'BEGIN {FS = "|"}; 
    {print "---------------->\nname: " $1 "\naddress: " $2 "\nphone: " $3"\n<----------------"}'
fi
