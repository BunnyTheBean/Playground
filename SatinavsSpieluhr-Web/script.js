const absoluteDayField = document.getElementById("absoluteDay");
const dayField = document.getElementById("day");
const monthField = document.getElementById("month");
const yearField = document.getElementById("year");
const weekdayField = document.getElementById("weekday");
const lunarPhaseField = document.getElementById("lunarPhase");

const getAbsoluteDay = () => Number(absoluteDayField.value);
const getDayOfMonth = () => Number(dayField.value);
const getMonth = () => Number(monthField.value);
const getYear = () => Number(yearField.value);
const getWeekday = () => Number(weekdayField.value);
const getLunarPhase = () => lunarPhaseField.value;

function calculateDayOfYear() {
    return (getAbsoluteDay() - 1) % 365 + 1;
}

function calculateDayOfMonth() {
    const dayOfYear = calculateDayOfYear();
    return (dayOfYear - 1) % 30 + 1;
}

function calculateMonthValue() {
    const dayOfYear = calculateDayOfYear();
    return Math.floor((dayOfYear - 1) / 30 + 1);
}

function calculateYear() {
    return Math.floor((getAbsoluteDay() - 1) / 365);
}

function calculateWeekdayValue() {
    return (getAbsoluteDay() - 1) % 7 + 1;
}

/*
Laut https://de.wiki-aventurica.de/wiki/Mond finden Tote Made, Kelch, Rad und 
Helm (also der jeweils 1. Tag der Phase) immer an einem Erdtag statt, also am zweiten 
Wochentag. Tag 1 sollte also den Wert "4" und Tag 2 den Wert "1" haben., wenn wir
davon ausgehen, dass die Wochentagszählung mit dem 1.1.0BF beginnt.
*/
function calculateLunarPhaseValue() {
    const day = getAbsoluteDay();
    
    if (day == 1) {
        return 4;
    }

    const absolutePhase = Math.floor((day - 2) / 7 + 1);
    return (absolutePhase - 1) % 4 + 1;
}

function getLunarPhaseNameFromValue(lunarPhaseValue) {
    switch (lunarPhaseValue) {
        case 1: return "Tote Mada";
        case 2: return "Kelch";
        case 3: return "Rad";
        case 4: return "Helm";
        default: return "Kaputter Mond, upsi";
    }
}

function getWeekdayNameFromValue(weekdayValue) {
    switch (weekdayValue) {
        case 1: return "Windstag";
        case 2: return "Erdtag";
        case 3: return "Markttag";
        case 4: return "Praiostag";
        case 5: return "Rohalstag";
        case 6: return "Feuertag";
        case 7: return "Wassertag";
        default: return "Fehlerstag";
    }
}

function setAllFieldsFromAbsoluteDay() {
    dayField.value = calculateDayOfMonth();
    monthField.value = calculateMonthValue();
    yearField.value = calculateYear();
    weekdayField.innerHTML = getWeekdayNameFromValue(calculateWeekdayValue());
    lunarPhaseField.innerHTML = getLunarPhaseNameFromValue(calculateLunarPhaseValue());
}

function setAbsoluteDayFromDate() {
    
}

function test() {
    setAllFieldsFromAbsoluteDay();
}