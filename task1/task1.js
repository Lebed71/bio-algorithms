const patternConcurrencyCount = (inputString = '', patternString = '') => {
    if (!inputString.length || !patternString.length) return 0;

    let total = 0;
    let position = -1;

    while (~(position = inputString.indexOf(patternString, position + 1))) {
        total++;
    }

    return total;
};

const fs = require('fs');
const lineReader = require('readline').createInterface({
    input: fs.createReadStream('input.txt')
});

let buffer = [];
lineReader.on('line', (line) => {
    buffer.push(line);

    if (buffer.length === 2) {
        const inputString = buffer[0];
        const patternString = buffer[1];
        const totalResult = patternConcurrencyCount(inputString, patternString);

        fs.writeFile('output.txt', totalResult.toString(), (err) => {
            if (err) console.log(err);
            console.log('Successfully!');
        });
    }
});

module.exports = patternConcurrencyCount;

