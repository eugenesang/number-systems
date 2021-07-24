secondDivisor=(number, firstDivisor)=>{
    if(number%firstDivisor!=0) number-=number%firstDivisor;
    return number/firstDivisor;
};

class LocalString{
    constructor(string){
        this.content=string,
        this.length=string.length
    }
codeOf(letter){
    for (let i=0; i<this.length; i++){
        if(letter== this.content[i]) return i;
    }
    return -1;
}
charAt(position){
return this.content[position]
}
};

makeNewValues=(number,  newBase)=>{
    let array=new Array();
    if(number==0){
        array.push(0);
    }else{
        while(number>0){
            array.push(number%newBase);
            number=secondDivisor(number, newBase);
        };
    }
    array.reverse();
    return array
}
convertToNewSystem=(baseTenNumber, localString)=>{
    let array=makeNewValues(baseTenNumber, localString.length);
    let string="";
    for(number of array){
        string+=localString.charAt(number);
    }
    return string;
};
let myStr=new LocalString("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

toBaseTen=(number, myString)=>{
    let array=new Array();
    for(let letter of number){
        array.push(myString.codeOf(letter));
    };
    array.reverse();
    let answer=0;
    for(let num=0; num<array.length; num++){
        answer+=array[num]*Math.pow(myString.length, num);
    };
    return answer;
}
console.log(toBaseTen("Eugene", myStr))