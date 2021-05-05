var changeCss = document.getElementsByClassName('changeCss')[0];
var home = document.getElementsByClassName('home')[0];
var i = 0;
changeCss.onclick = function name() {
    i++;
    if (i % 2) {
        document.getElementsByClassName("home")[0].style.fontSize = '100px';
    } else {
        document.getElementsByClassName("home")[0].style.fontSize = '';
    }
}