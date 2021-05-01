let lightTheme = "styles/light.css";
let darkTheme = "styles/dark.css";
var varNumber;
// Clears the screen on click of C button.
function clearScreen() {
  document.getElementById("result").value = "";
}
// Displays entered value on screen.
function liveScreen(value) {
  document.getElementById("result").value += value;
}
//apply trigo function.
function trigo(func) {
  document.getElementById("result").value = func+"("+document.getElementById("result").value+")";
}
//calc cos
function cos(a) {
  return Math.cos(a);
}
//calc sin
function sin(a) {
  return Math.sin(a);
}
//calc tan
function tan(a) {
  return Math.tan(a);
}
//calc acos
function acos(a) {
  return Math.acos(a);
}
//calc asin
function asin(a) {
  return Math.asin(a);
}
//calc tan
function atan(a) {
  return Math.atan(a);
}
//arc trigo.
function second() {
  if (document.getElementById("cos").value == "cos()") {
    document.getElementById("cos").value = "acos()";
  } else {
    document.getElementById("cos").value = "cos()";
  }
  if (document.getElementById("sin").value == "sin()") {
    document.getElementById("sin").value = "asin()";
  } else {
    document.getElementById("sin").value = "sin()";
  }
  if (document.getElementById("tan").value == "tan()") {
    document.getElementById("tan").value = "atan()";
  } else {
    document.getElementById("tan").value = "tan()";
  }
}
//apply sqr.
function sqr() {
  document.getElementById("result").value = "sqrt("+document.getElementById("result").value+")";
}
function sqrt(a) {
  return Math.sqrt(a);
}
// Swaps the style sheet in order to  achieve dark mode.
function changeTheme() {
  let darkMode = document.getElementById("dark-mode");
  let theme = document.getElementById("theme");
  if (theme.getAttribute("href") == lightTheme) {
    theme.href = darkTheme;
    darkMode.innerHTML = "Light Mode 🌞";
  } else {
    theme.href = lightTheme;
    darkMode.innerHTML = "Dark Mode 🌙";
  }
}
