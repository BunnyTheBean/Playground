const { readFile, writeFile } = require('fs');

readFile('./content/first.txt', 'utf-8', (error, result) => {
    if (error) {
        console.log(error);
        return;
    }
    const first = result;
    readFile('./content/second.txt', 'utf-8', (error, result) => {
        if (error) {
            console.log(error);
            return;
        }
        const second = result;
        writeFile('./content/result-async.txt', `${first}\n${second}`, (error, result) => {
            if (error) {
                console.log(error);
                return;
            }
            console.log("DONE!");
        })
    })
});

console.log("At the end");