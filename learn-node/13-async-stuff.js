const { readFile, writeFile } = require('fs').promises;

const start = async() => {
    try {
        const first = await readFile('./content/first.txt', 'utf-8');
        const second = await readFile('./content/second.txt', 'utf-8');
        await writeFile('./content/result.txt', `THIS IS... ${first} ${second}`);
        console.log(first, second);
    } catch(error) {
        console.log(error);
    }
}

start();
for (let i = 0; i < 999; i++) {
    console.log("HI I GO FIRST");
}
