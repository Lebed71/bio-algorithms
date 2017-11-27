const patternConcurrencyCount  = require('../task1/task1');

function frequentWords(inputString, k) {
    if (!inputString.length || (+k === 0)) return '';

    const N = inputString.length + 1;

    let frequentPattern = '';
    let summary = new Array(N - k + 1);
    console.log(N, k, summary.length);
    for (let i = 0; i < summary.length; i++) {
        console.log(i, k, inputString, inputString.substring(i, i + k));
        summary[i] = patternConcurrencyCount(inputString, inputString.substring(i, i + k));
        console.log(summary[i]);
    }

    let lim = summary[0];
    for (let j = 1; j < summary.length; j++) {
        if (summary[j] > lim) {
            lim = summary[j];
        }
    }
    for (let j = 0; j < N - k + 1; j++) {
        if ((summary[j] === lim) && !patternConcurrencyCount(frequentPattern, inputString.substring(j, j + k))) {
            console.log(inputString.substring(j, j + k));
            frequentPattern += inputString.substring(j, j + k);
            frequentPattern += ' ';
        }
    }

    return frequentPattern;
}

const fs = require('fs');
const lineReader = require('readline').createInterface({
    input: fs.createReadStream('input.txt')
});

let buffer = [];
lineReader.on('line', (line) => {
    buffer.push(line);

    if (buffer.length === 2) {
        const inputString = buffer[0];
        const count = +buffer[1];
        const frequentPattern = frequentWords(inputString, count);

        fs.writeFile('output.txt', frequentPattern.toString(), (err) => {
            if (err) console.log(err);
            console.log('Successfully!');
        });
    }
});
