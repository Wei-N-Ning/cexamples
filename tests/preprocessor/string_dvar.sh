#!/usr/bin/env bash

# source
# wkou code base
# CXXFLAGS := \
#    -DSOME=123 \
#    '-DSOMESTRING="STRING"' \
#
# if a DVAR is to hold a c string
# quote the -D arg in single quotes
# and the string value in double quotes


set -e

CC=$( which cc )
SUT=/tmp/sut.c

cat > ${SUT} <<EOF
int main() {
    const char* text = SOMETHING_DARKSIDE;
    if (! text) {
        return 1;
    }
    if (text[0] != '0') {
        return 1;
    }
    return 0;
}
EOF

${CC} ${SUT} '-DSOMETHING_DARKSIDE="0x13"' -o /tmp/out
/tmp/out
if [[ $? != 0 ]]
then
    echo "failed"
    exit 1
fi

echo "passed"
