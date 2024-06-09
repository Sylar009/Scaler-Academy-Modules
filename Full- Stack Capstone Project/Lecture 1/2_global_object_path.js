const path=require("path");
const fs=require("fs");

//this represents features inside nodejs
// console.log(global);

//it represent currently running nodejs process
// console.log(process);

// filename: '/Users/abhishekgoel/fsCapstone27thMay/Lecture1/2_global_objects_path.js',

console.log(__filename);
console.log(__dirname);

const fileExt=path.extname(__filename);
console.log("file extension ->",fileExt);

const fileName=path.basename(__filename);
console.log("fileName ->",fileName);

const dirName=path.dirname(__filename);
console.log("dirName ->",dirName);


// i want to create directory from lecture-2 to lecture-16

const projectPath=path.dirname(__dirname);
console.log(projectPath);
for(let i=2;i<=16;i++){
    let pathName=path.join(projectPath,`Lecture${i}`);
    // console.log(pathName);
    fs.mkdirSync(pathName);
}

// /Users/abhishekgoel/fsCapstone27thMay/Lecture1 -> macos 
// \Users\abhishekgoel\fsCapstone27thMay\Lecture1 -> windows