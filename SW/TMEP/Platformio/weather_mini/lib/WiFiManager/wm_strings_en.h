/**
 * wm_strings_en.h
 * engligh strings for
 * WiFiManager, a library for the ESP8266/Arduino platform
 * for configuration of WiFi credentials using a Captive Portal
 *
 * @author Creator tzapu
 * @author tablatronix
 * @version 0.0.0
 * @license MIT
 */

#ifndef _WM_STRINGS_EN_H_
#define _WM_STRINGS_EN_H_


#ifndef WIFI_MANAGER_OVERRIDE_STRINGS
// !!! ABOVE WILL NOT WORK if you define in your sketch, must be build flag, if anyone one knows how to order includes to be able to do this it would be neat.. I have seen it done..

// strings files must include a consts file!
#include "wm_consts_en.h" // include constants, tokens, routes

const char WM_LANGUAGE[] PROGMEM = "en-US"; // i18n lang code

const char HTTP_HEAD_START[]       PROGMEM = "<!DOCTYPE html>"
"<html lang='en'><head>"
"<meta name='format-detection' content='telephone=no'>"
"<meta charset='UTF-8'>"
"<meta  name='viewport' content='width=device-width,initial-scale=1,user-scalable=no'/>"
"<title>{v}</title>";

const char HTTP_SCRIPT[]           PROGMEM = "<script>function c(l){"
"document.getElementById('s').value=l.getAttribute('data-ssid')||l.innerText||l.textContent;"
"p = l.nextElementSibling.classList.contains('l');"
"document.getElementById('p').disabled = !p;"
"if(p)document.getElementById('p').focus();};"
"function f() {var x = document.getElementById('p');x.type==='password'?x.type='text':x.type='password';}"
"</script>"; // @todo add button states, disable on click , show ack , spinner etc

const char HTTP_HEAD_END[]         PROGMEM = "</head><body class='{c}'><div class='wrap'>"; // {c} = _bodyclass
// example of embedded logo, base64 encoded inline, No styling here
const char HTTP_ROOT_MAIN[]        PROGMEM = "<div style='text-align: center;'><h3>WiFiManager</h3><img title=' alt=' src='data:image/jpeg;base64,iVBORw0KGgoAAAANSUhEUgAAAOgAAAA8CAYAAABsBvZBAAAACXBIWXMAACxLAAAsSwGlPZapAAAE9GlUWHRYTUw6Y29tLmFkb2JlLnhtcAAAAAAAPD94cGFja2V0IGJlZ2luPSLvu78iIGlkPSJXNU0wTXBDZWhpSHpyZVN6TlRjemtjOWQiPz4gPHg6eG1wbWV0YSB4bWxuczp4PSJhZG9iZTpuczptZXRhLyIgeDp4bXB0az0iQWRvYmUgWE1QIENvcmUgNy4xLWMwMDAgNzkuZWRhMmIzZmFjLCAyMDIxLzExLzE3LTE3OjIzOjE5ICAgICAgICAiPiA8cmRmOlJERiB4bWxuczpyZGY9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkvMDIvMjItcmRmLXN5bnRheC1ucyMiPiA8cmRmOkRlc2NyaXB0aW9uIHJkZjphYm91dD0iIiB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iIHhtbG5zOmRjPSJodHRwOi8vcHVybC5vcmcvZGMvZWxlbWVudHMvMS4xLyIgeG1sbnM6cGhvdG9zaG9wPSJodHRwOi8vbnMuYWRvYmUuY29tL3Bob3Rvc2hvcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RFdnQ9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZUV2ZW50IyIgeG1wOkNyZWF0b3JUb29sPSJBZG9iZSBQaG90b3Nob3AgMjMuMSAoTWFjaW50b3NoKSIgeG1wOkNyZWF0ZURhdGU9IjIwMjEtMDctMTJUMTg6NDk6MTcrMDI6MDAiIHhtcDpNb2RpZnlEYXRlPSIyMDIxLTEyLTIwVDE0OjA5OjUwKzAxOjAwIiB4bXA6TWV0YWRhdGFEYXRlPSIyMDIxLTEyLTIwVDE0OjA5OjUwKzAxOjAwIiBkYzpmb3JtYXQ9ImltYWdlL3BuZyIgcGhvdG9zaG9wOkNvbG9yTW9kZT0iMyIgeG1wTU06SW5zdGFuY2VJRD0ieG1wLmlpZDpkNGQwNDYxZS03MjkwLTQwNTctOGRmNy1iZjEzYTAyZTI1MTkiIHhtcE1NOkRvY3VtZW50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' /><h2>{v}</h2></div>";
//const char HTTP_ROOT_MAIN[]        PROGMEM = "<h1>{t}</h1><h3>{v}</h3>";


const char * const HTTP_PORTAL_MENU[] PROGMEM = {
"<form action='/wifi'    method='get'><button>Configure WiFi</button></form><br/>\n", // MENU_WIFI
"<form action='/0wifi'   method='get'><button>Configure WiFi (No scan)</button></form><br/>\n", // MENU_WIFINOSCAN
"<form action='/info'    method='get'><button>Info</button></form><br/>\n", // MENU_INFO
"<form action='/param'   method='get'><button>Setup</button></form><br/>\n",//MENU_PARAM
"<form action='/close'   method='get'><button>Close</button></form><br/>\n", // MENU_CLOSE
"<form action='/restart' method='get'><button>Restart</button></form><br/>\n",// MENU_RESTART
"<form action='/exit'    method='get'><button>Exit</button></form><br/>\n",  // MENU_EXIT
"<form action='/erase'   method='get'><button class='D'>Erase</button></form><br/>\n", // MENU_ERASE
"<form action='/update'  method='get'><button>Update</button></form><br/>\n",// MENU_UPDATE
"<hr><br/>" // MENU_SEP
};

// const char HTTP_PORTAL_OPTIONS[]   PROGMEM = strcat(HTTP_PORTAL_MENU[0] , HTTP_PORTAL_MENU[3] , HTTP_PORTAL_MENU[7]);
const char HTTP_PORTAL_OPTIONS[]   PROGMEM = "";
const char HTTP_ITEM_QI[]          PROGMEM = "<div role='img' aria-label='{r}%' title='{r}%' class='q q-{q} {i} {h}'></div>"; // rssi icons
const char HTTP_ITEM_QP[]          PROGMEM = "<div class='q {h}'>{r}%</div>"; // rssi percentage {h} = hidden showperc pref
const char HTTP_ITEM[]             PROGMEM = "<div><a href='#p' onclick='c(this)' data-ssid='{V}'>{v}</a>{qi}{qp}</div>"; // {q} = HTTP_ITEM_QI, {r} = HTTP_ITEM_QP
// const char HTTP_ITEM[]            PROGMEM = "<div><a href='#p' onclick='c(this)'>{v}</a> {R} {r}% {q} {e}</div>"; // test all tokens

const char HTTP_FORM_START[]       PROGMEM = "<form method='POST' action='{v}'>";
const char HTTP_FORM_WIFI[]        PROGMEM = "<label for='s'>SSID</label><input id='s' name='s' maxlength='32' autocorrect='off' autocapitalize='none' placeholder='{v}'><br/><label for='p'>Password</label><input id='p' name='p' maxlength='64' type='password' placeholder='{p}'><input type='checkbox' id='showpass' onclick='f()'> <label for='showpass'>Show Password</label><br/>";
const char HTTP_FORM_WIFI_END[]    PROGMEM = "";
const char HTTP_FORM_STATIC_HEAD[] PROGMEM = "<hr><br/>";
const char HTTP_FORM_END[]         PROGMEM = "<br/><br/><button type='submit'>Save</button></form>";
const char HTTP_FORM_LABEL[]       PROGMEM = "<label for='{i}'>{t}</label>";
const char HTTP_FORM_PARAM_HEAD[]  PROGMEM = "<hr><br/>";
const char HTTP_FORM_PARAM[]       PROGMEM = "<br/><input id='{i}' name='{n}' maxlength='{l}' value='{v}' {c}>\n"; // do not remove newline!

const char HTTP_SCAN_LINK[]        PROGMEM = "<br/><form action='/wifi?refresh=1' method='POST'><button name='refresh' value='1'>Refresh</button></form>";
const char HTTP_SAVED[]            PROGMEM = "<div class='msg'>Saving Credentials<br/>Trying to connect ESP to network.<br />If it fails reconnect to AP to try again</div>";
const char HTTP_PARAMSAVED[]       PROGMEM = "<div class='msg S'>Saved<br/></div>";
const char HTTP_END[]              PROGMEM = "</div></body></html>";
const char HTTP_ERASEBTN[]         PROGMEM = "<br/><form action='/erase' method='get'><button class='D'>Erase WiFi config</button></form>";
const char HTTP_UPDATEBTN[]        PROGMEM = "<br/><form action='/update' method='get'><button>Update</button></form>";
const char HTTP_BACKBTN[]          PROGMEM = "<hr><br/><form action='/' method='get'><button>Back</button></form>";

const char HTTP_STATUS_ON[]        PROGMEM = "<div class='msg S'><strong>Connected</strong> to {v}<br/><em><small>with IP {i}</small></em></div>";
const char HTTP_STATUS_OFF[]       PROGMEM = "<div class='msg {c}'><strong>Not connected</strong> to {v}{r}</div>"; // {c=class} {v=ssid} {r=status_off}
const char HTTP_STATUS_OFFPW[]     PROGMEM = "<br/>Authentication failure"; // STATION_WRONG_PASSWORD,  no eps32
const char HTTP_STATUS_OFFNOAP[]   PROGMEM = "<br/>AP not found";   // WL_NO_SSID_AVAIL
const char HTTP_STATUS_OFFFAIL[]   PROGMEM = "<br/>Could not connect"; // WL_CONNECT_FAILED
const char HTTP_STATUS_NONE[]      PROGMEM = "<div class='msg'>No AP set</div>";
const char HTTP_BR[]               PROGMEM = "<br/>";

const char HTTP_STYLE[]            PROGMEM = "<style>"
".c,body{text-align:center;font-family:verdana}div,input,select{padding:5px;font-size:1em;margin:5px 0;box-sizing:border-box}"
"input,button,select,.msg{border-radius:.3rem;width: 100%}input[type=radio],input[type=checkbox]{width:auto}"
"button,input[type='button'],input[type='submit']{cursor:pointer;border:0;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%}"
"input[type='file']{border:1px solid #1fa3ec}"
".wrap {text-align:left;display:inline-block;min-width:260px;max-width:500px}"
// links
"a{color:#000;font-weight:700;text-decoration:none}a:hover{color:#1fa3ec;text-decoration:underline}"
// quality icons
".q{height:16px;margin:0;padding:0 5px;text-align:right;min-width:38px;float:right}.q.q-0:after{background-position-x:0}.q.q-1:after{background-position-x:-16px}.q.q-2:after{background-position-x:-32px}.q.q-3:after{background-position-x:-48px}.q.q-4:after{background-position-x:-64px}.q.l:before{background-position-x:-80px;padding-right:5px}.ql .q{float:left}.q:after,.q:before{content:'';width:16px;height:16px;display:inline-block;background-repeat:no-repeat;background-position: 16px 0;"
"background-image:url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGAAAAAQCAMAAADeZIrLAAAAJFBMVEX///8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADHJj5lAAAAC3RSTlMAIjN3iJmqu8zd7vF8pzcAAABsSURBVHja7Y1BCsAwCASNSVo3/v+/BUEiXnIoXkoX5jAQMxTHzK9cVSnvDxwD8bFx8PhZ9q8FmghXBhqA1faxk92PsxvRc2CCCFdhQCbRkLoAQ3q/wWUBqG35ZxtVzW4Ed6LngPyBU2CobdIDQ5oPWI5nCUwAAAAASUVORK5CYII=');}"
// icons @2x media query (32px rescaled)
"@media (-webkit-min-device-pixel-ratio: 2),(min-resolution: 192dpi){.q:before,.q:after {"
"background-image:url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAALwAAAAgCAMAAACfM+KhAAAALVBMVEX///8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADAOrOgAAAADnRSTlMAESIzRGZ3iJmqu8zd7gKjCLQAAACmSURBVHgB7dDBCoMwEEXRmKlVY3L//3NLhyzqIqSUggy8uxnhCR5Mo8xLt+14aZ7wwgsvvPA/ofv9+44334UXXngvb6XsFhO/VoC2RsSv9J7x8BnYLW+AjT56ud/uePMdb7IP8Bsc/e7h8Cfk912ghsNXWPpDC4hvN+D1560A1QPORyh84VKLjjdvfPFm++i9EWq0348XXnjhhT+4dIbCW+WjZim9AKk4UZMnnCEuAAAAAElFTkSuQmCC');"
"background-size: 95px 16px;}}"
// msg callouts
".msg{padding:20px;margin:20px 0;border:1px solid #eee;border-left-width:5px;border-left-color:#777}.msg h4{margin-top:0;margin-bottom:5px}.msg.P{border-left-color:#1fa3ec}.msg.P h4{color:#1fa3ec}.msg.D{border-left-color:#dc3630}.msg.D h4{color:#dc3630}.msg.S{border-left-color: #5cb85c}.msg.S h4{color: #5cb85c}"
// lists
"dt{font-weight:bold}dd{margin:0;padding:0 0 0.5em 0;min-height:12px}"
"td{vertical-align: top;}"
".h{display:none}"
"button{transition: 0s opacity;transition-delay: 3s;transition-duration: 0s;cursor: pointer}"
"button.D{background-color:#dc3630}"
"button:active{opacity:50% !important;cursor:wait;transition-delay: 0s}"
// invert
"body.invert{background-color:#060606;}"
"body.invert,body.invert a,body.invert h1 {color:#fff;}"
"body.invert .msg{color:#fff;background-color:#282828;border-top:1px solid #555;border-right:1px solid #555;border-bottom:1px solid #555;}"
"body.invert .q[role=img]{-webkit-filter:invert(1);filter:invert(1);}"
":disabled {opacity: 0.5;}"
"</style>";

#ifndef WM_NOHELP
const char HTTP_HELP[]             PROGMEM =
 "<br/><h3>Available pages</h3><hr>"
 "<table class='table'>"
 "<thead><tr><th>Page</th><th>Function</th></tr></thead><tbody>"
 "<tr><td><a href='/'>/</a></td>"
 "<td>Menu page.</td></tr>"
 "<tr><td><a href='/wifi'>/wifi</a></td>"
 "<td>Show WiFi scan results and enter WiFi configuration.(/0wifi noscan)</td></tr>"
 "<tr><td><a href='/wifisave'>/wifisave</a></td>"
 "<td>Save WiFi configuration information and configure device. Needs variables supplied.</td></tr>"
 "<tr><td><a href='/param'>/param</a></td>"
 "<td>Parameter page</td></tr>"
 "<tr><td><a href='/info'>/info</a></td>"
 "<td>Information page</td></tr>"
 "<tr><td><a href='/u'>/u</a></td>"
 "<td>OTA Update</td></tr>"
 "<tr><td><a href='/close'>/close</a></td>"
 "<td>Close the captiveportal popup, config portal will remain active</td></tr>"
 "<tr><td>/exit</td>"
 "<td>Exit Config portal, config portal will close</td></tr>"
 "<tr><td>/restart</td>"
 "<td>Reboot the device</td></tr>"
 "<tr><td>/erase</td>"
 "<td>Erase WiFi configuration and reboot device. Device will not reconnect to a network until new WiFi configuration data is entered.</td></tr>"
 "</table>"
 "<p/>Github <a href='https://github.com/tzapu/WiFiManager'>https://github.com/tzapu/WiFiManager</a>.";
#else
const char HTTP_HELP[]             PROGMEM = "";
#endif

const char HTTP_UPDATE[] PROGMEM = "Upload new firmware<br/><form method='POST' action='u' enctype='multipart/form-data' onchange=\"(function(el){document.getElementById('uploadbin').style.display = el.value=='' ? 'none' : 'initial';})(this)\"><input type='file' name='update' accept='.bin,application/octet-stream'><button id='uploadbin' type='submit' class='h D'>Update</button></form><small><a href='http://192.168.4.1/update' target='_blank'>* May not function inside captive portal, open in browser http://192.168.4.1</a></small>";
const char HTTP_UPDATE_FAIL[] PROGMEM = "<div class='msg D'><strong>Update failed!</strong><Br/>Reboot device and try again</div>";
const char HTTP_UPDATE_SUCCESS[] PROGMEM = "<div class='msg S'><strong>Update successful.  </strong> <br/> Device rebooting now...</div>";

#ifdef WM_JSTEST
const char HTTP_JS[] PROGMEM =
"<script>function postAjax(url, data, success) {"
"    var params = typeof data == 'string' ? data : Object.keys(data).map("
"            function(k){ return encodeURIComponent(k) + '=' + encodeURIComponent(data[k]) }"
"        ).join('&');"
"    var xhr = window.XMLHttpRequest ? new XMLHttpRequest() : new ActiveXObject(\"Microsoft.XMLHTTP\");"
"    xhr.open('POST', url);"
"    xhr.onreadystatechange = function() {"
"        if (xhr.readyState>3 && xhr.status==200) { success(xhr.responseText); }"
"    };"
"    xhr.setRequestHeader('X-Requested-With', 'XMLHttpRequest');"
"    xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');"
"    xhr.send(params);"
"    return xhr;}"
"postAjax('/status', 'p1=1&p2=Hello+World', function(data){ console.log(data); });"
"postAjax('/status', { p1: 1, p2: 'Hello World' }, function(data){ console.log(data); });"
"</script>";
#endif

// Info html
// @todo remove html elements from progmem, repetetive strings
#ifdef ESP32
	const char HTTP_INFO_esphead[]    PROGMEM = "<h3>esp32</h3><hr><dl>";
	const char HTTP_INFO_chiprev[]    PROGMEM = "<dt>Chip rev</dt><dd>{1}</dd>";
  	const char HTTP_INFO_lastreset[]  PROGMEM = "<dt>Last reset reason</dt><dd>CPU0: {1}<br/>CPU1: {2}</dd>";
  	const char HTTP_INFO_aphost[]     PROGMEM = "<dt>Access point hostname</dt><dd>{1}</dd>";
    const char HTTP_INFO_psrsize[]    PROGMEM = "<dt>PSRAM Size</dt><dd>{1} bytes</dd>";
	const char HTTP_INFO_temp[]       PROGMEM = "<dt>Temperature</dt><dd>{1} C&deg; / {2} F&deg;</dd>";
    const char HTTP_INFO_hall[]       PROGMEM = "<dt>Hall</dt><dd>{1}</dd>";
#else
	const char HTTP_INFO_esphead[]    PROGMEM = "<h3>esp8266</h3><hr><dl>";
	const char HTTP_INFO_fchipid[]    PROGMEM = "<dt>Flash chip ID</dt><dd>{1}</dd>";
	const char HTTP_INFO_corever[]    PROGMEM = "<dt>Core version</dt><dd>{1}</dd>";
	const char HTTP_INFO_bootver[]    PROGMEM = "<dt>Boot version</dt><dd>{1}</dd>";
	const char HTTP_INFO_lastreset[]  PROGMEM = "<dt>Last reset reason</dt><dd>{1}</dd>";
	const char HTTP_INFO_flashsize[]  PROGMEM = "<dt>Real flash size</dt><dd>{1} bytes</dd>";
#endif

const char HTTP_INFO_memsmeter[]  PROGMEM = "<br/><progress value='{1}' max='{2}'></progress></dd>";
const char HTTP_INFO_memsketch[]  PROGMEM = "<dt>Memory - Sketch size</dt><dd>Used / Total bytes<br/>{1} / {2}";
const char HTTP_INFO_freeheap[]   PROGMEM = "<dt>Memory - Free heap</dt><dd>{1} bytes available</dd>";
const char HTTP_INFO_wifihead[]   PROGMEM = "<br/><h3>WiFi</h3><hr>";
const char HTTP_INFO_uptime[]     PROGMEM = "<dt>Uptime</dt><dd>{1} mins {2} secs</dd>";
const char HTTP_INFO_chipid[]     PROGMEM = "<dt>Chip ID</dt><dd>{1}</dd>";
const char HTTP_INFO_idesize[]    PROGMEM = "<dt>Flash size</dt><dd>{1} bytes</dd>";
const char HTTP_INFO_sdkver[]     PROGMEM = "<dt>SDK version</dt><dd>{1}</dd>";
const char HTTP_INFO_cpufreq[]    PROGMEM = "<dt>CPU frequency</dt><dd>{1}MHz</dd>";
const char HTTP_INFO_apip[]       PROGMEM = "<dt>Access point IP</dt><dd>{1}</dd>";
const char HTTP_INFO_apmac[]      PROGMEM = "<dt>Access point MAC</dt><dd>{1}</dd>";
const char HTTP_INFO_apssid[]     PROGMEM = "<dt>Access point SSID</dt><dd>{1}</dd>";
const char HTTP_INFO_apbssid[]    PROGMEM = "<dt>BSSID</dt><dd>{1}</dd>";
const char HTTP_INFO_stassid[]    PROGMEM = "<dt>Station SSID</dt><dd>{1}</dd>";
const char HTTP_INFO_staip[]      PROGMEM = "<dt>Station IP</dt><dd>{1}</dd>";
const char HTTP_INFO_stagw[]      PROGMEM = "<dt>Station gateway</dt><dd>{1}</dd>";
const char HTTP_INFO_stasub[]     PROGMEM = "<dt>Station subnet</dt><dd>{1}</dd>";
const char HTTP_INFO_dnss[]       PROGMEM = "<dt>DNS Server</dt><dd>{1}</dd>";
const char HTTP_INFO_host[]       PROGMEM = "<dt>Hostname</dt><dd>{1}</dd>";
const char HTTP_INFO_stamac[]     PROGMEM = "<dt>Station MAC</dt><dd>{1}</dd>";
const char HTTP_INFO_conx[]       PROGMEM = "<dt>Connected</dt><dd>{1}</dd>";
const char HTTP_INFO_autoconx[]   PROGMEM = "<dt>Autoconnect</dt><dd>{1}</dd>";

const char HTTP_INFO_aboutver[]     PROGMEM = "<dt>LaskaKit</dt><dd>{1}</dd>";
const char HTTP_INFO_aboutarduino[] PROGMEM = "<dt>Arduino</dt><dd>{1}</dd>";
const char HTTP_INFO_aboutsdk[]     PROGMEM = "<dt>ESP-SDK/IDF</dt><dd>{1}</dd>";
const char HTTP_INFO_aboutdate[]    PROGMEM = "<dt>Build date</dt><dd>{1}</dd>";

const char S_brand[]              PROGMEM = "LaskaKit";
const char S_debugPrefix[]        PROGMEM = "*wm:";
const char S_y[]                  PROGMEM = "Yes";
const char S_n[]                  PROGMEM = "No";
const char S_enable[]             PROGMEM = "Enabled";
const char S_disable[]            PROGMEM = "Disabled";
const char S_GET[]                PROGMEM = "GET";
const char S_POST[]               PROGMEM = "POST";
const char S_NA[]                 PROGMEM = "Unknown";
const char S_passph[]             PROGMEM = "********";
const char S_titlewifisaved[]     PROGMEM = "Credentials saved";
const char S_titlewifisettings[]  PROGMEM = "Settings saved";
const char S_titlewifi[]          PROGMEM = "Config ESP";
const char S_titleinfo[]          PROGMEM = "Info";
const char S_titleparam[]         PROGMEM = "Setup";
const char S_titleparamsaved[]    PROGMEM = "Setup saved";
const char S_titleexit[]          PROGMEM = "Exit";
const char S_titlereset[]         PROGMEM = "Reset";
const char S_titleerase[]         PROGMEM = "Erase";
const char S_titleclose[]         PROGMEM = "Close";
const char S_options[]            PROGMEM = "options";
const char S_nonetworks[]         PROGMEM = "No networks found. Refresh to scan again.";
const char S_staticip[]           PROGMEM = "Static IP";
const char S_staticgw[]           PROGMEM = "Static gateway";
const char S_staticdns[]          PROGMEM = "Static DNS";
const char S_subnet[]             PROGMEM = "Subnet";
const char S_exiting[]            PROGMEM = "Exiting";
const char S_resetting[]          PROGMEM = "Module will reset in a few seconds.";
const char S_closing[]            PROGMEM = "You can close the page, portal will continue to run";
const char S_error[]              PROGMEM = "An error occured";
const char S_notfound[]           PROGMEM = "File not found\n\n";
const char S_uri[]                PROGMEM = "URI: ";
const char S_method[]             PROGMEM = "\nMethod: ";
const char S_args[]               PROGMEM = "\nArguments: ";
const char S_parampre[]           PROGMEM = "param_";

// debug strings
const char D_HR[]                 PROGMEM = "--------------------";


// softap ssid default prefix
#ifdef ESP8266
    const char S_ssidpre[]        PROGMEM = "ESP";
#elif defined(ESP32)
    const char S_ssidpre[]        PROGMEM = "ESP32";
#else
    const char S_ssidpre[]        PROGMEM = "WM";
#endif

// END WIFI_MANAGER_OVERRIDE_STRINGS
#endif

#endif
