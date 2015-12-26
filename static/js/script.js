$(document).ready(function() {
	/*
	 * First updates:
	*/
	Clock_update();
	Calendar_update();
	/*
	 * Interval updates:
	*/
	window.setInterval(Clock_update, 500);
	window.setInterval(Calendar_update, 5000);
});
/*
 * Clock Widget:
*/
function Clock_update() {
	var now = new Date();
	$("#clockHours").html(now.format("H"));
	$("#clockMinutes").html(now.format("i"));
	$("#clockSeconds").html(now.format("s"));
}
/*
 * Calendar Widget:
*/
function Calendar_getFirstMonday(date) {
	var res = new Date(+date);
	while (parseInt(res.format('N')) !== 1) {
		res = new Date(date.getTime() - 86400000);
	}
	return res;
}

function Calendar_update() {
	var i = 0;
	var now = new Date();
	var monthBegin = new Date(now.getFullYear(), now.getMonth(), 1);
	$("#calendar th").each(function() {
		if (i > 7) {
			$(this).html((new Date(monthBegin.getTime() + (i-8)*604800000)).format('W'));
		};
		++i;
	});
	i = 0;
	var calendarBegin = Calendar_getFirstMonday(monthBegin);
	$("#calendar td").each(function() {
		var d = new Date(calendarBegin.getTime() + i*86400000);
		$(this).html(d.format('j'));
		if (d.getMonth() === now.getMonth()) {
			$(this).removeClass("ia");
			if (d.getDate() === now.getDate()) {
				$(this).addClass("today");
			};
		} else {
			$(this).addClass("ia");
		};
		++i;
	});
}
