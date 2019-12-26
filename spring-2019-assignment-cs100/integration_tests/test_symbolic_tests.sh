
#!/bin/sh



# test #1  "[ -e ../header/ctree.hpp ]" command
# test #2  "[ -f ../header/ctree.hpp ]" command
# test #3  "[ -d ../header/ctree.hpp ]" command
# test #4  "[ ../header/ctree.hpp ]" command

INPUTS=("[ -e ../header/ctree.hpp ]"
        "[ -f ../header/ctree.hpp ]"
        "[ -d ../header/ctree.hpp ]"
        "[ ../header/ctree.hpp ]")

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

#test #5 "[ -e ../header ]" command
#test #6 "[ -f ../header ]" command
#test #7 "[ test -d ../header ]" command
#test #8 "[ test ../header ]" command

INPUTS=("[ -e ../header ]"
        "[ -f ../header ]"
        "[ -d ../header ]"
        "[ ../header ]")
          
for input in "${INPUTS[@]}"
        
do
        echo executing: ${input}
        ./../rshell
done

#test #9 "[ ../header ] || echo failed"
#test #11 "[ -f ../header ]; echo test passed"
#test #12 "[ -d ../header/ctree.hpp ] && echco test failed"
#test #13 "echo D; exit && [ -f ../header ]"

INPUTS=("[ ../header ] || echo failed"
        "[ -f ../header ]; echo test passed"
        "[ -d ../header/ctree.hpp ] && echco test failed"
        "echo D; exit && [ -f ../header ]")

for input in "${INPUTS[@]}"

do
        echo executing: ${input}
        ./../rshell
done

