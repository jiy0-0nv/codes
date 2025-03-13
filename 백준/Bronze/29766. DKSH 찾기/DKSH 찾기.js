const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
});

let input = [];

readline.on('line', function(line) {
    input.push(line);
}).on('close', function(){
    let s = input[0];
    let count = 0;
    let index = 0;
    while (index < s.length) {
        var i = s.indexOf('DKSH', index);
        if (i === -1) break;
        count += 1;
        index = i + 4;
    }
    console.log(count);
    process.exit();
})