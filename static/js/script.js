var lastUpdateDay = (new Date()).getDate();
var Message_running = false;
var Message_queue = new Array();
var Message_timeout;

$(document).ready(function() {
	/*
	 * First updates:
	*/
	Clock_update();
	Calendar_update();
	//Weather_updateSun();
	Message_show("Hallo, Robert!", 5000, false);
	Message_show("Moin, du Null!", 5000, false);
	/*
	 * Interval updates:
	*/
	window.setInterval(Clock_update, 500);
	window.setInterval(function() {
		var day = (new Date()).getDate();
		if (lastUpdateDay !== day) {
			Calendar_update();
			Weather_updateSun();
			lastUpdateDay = day;
		};
	}, 5000);
});
/*
 * Clock Widget:
*/
function Clock_update() {
	var now = new Date();
	$("#clockHours").html(now.format("H"));
	$("#clockMinutes").html(now.format("i"));
	$("#clockSeconds").html(now.format("s"));
	$("#clockDate").html(now.format("d.m.Y"));
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
/*
 * Weather Widget:
*/
function Weather_updateSun() {
	$.ajax({
		url: "http://api.sunrise-sunset.org/json",
		jsonp: "callback",
		dataType: "jsonp",
		data: {
			lat: Config.lat,
			lng: Config.lon
		},
		success: function(resp) {
			if (resp.status === "OK") {
				$("#weatherSunrise").html(Weather_convertTime(resp.results.sunrise));
				$("#weatherSunset").html(Weather_convertTime(resp.results.sunset));
			} else {
				console.log("Error updating sunset/rise times.");
				console.log(resp);
			};
		}
	});
}
function Weather_convertTime(t) {
	var tParts = t.split(":");
	var tHour = parseInt(tParts[0]);
	var tMinute = parseInt(tParts[1]);
	var tParts2 = tParts[2].split(" ");
	if (tParts2[1] === "PM") {
		tHour += 12;
	};
	return sprintf("%02d:%02d", tHour, tMinute);
}
/*
 * Message Widget:
*/
function Message_show(text, dur, instantly) {
	if (Message_running && !instantly) {
		Message_queue.push({ "text": text, "duration": dur });
		console.log(Message_queue);
	} else {
		if (instantly) {
			window.clearTimeout(Message_timeout);
		};
		Message_set(text, dur);
	};
	$("#message").html();
}
function Message_set(text, dur) {
	Message_running = true;
	$("#message").html(text);
	$("#message").fadeIn(1000, function() {
		Message_timeout = window.setTimeout(function() {
			$("#message").fadeOut(1000, function() {
				/*
				 * Check for new message to show:
				*/
				if (Message_queue.length) {
					var m = Message_queue.shift();
					Message_set(m.text, m.duration);
				} else {
					Message_running = false;
				};
			});
		}, dur);
	});
}
