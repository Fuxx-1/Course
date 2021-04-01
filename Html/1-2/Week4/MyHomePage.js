! function (e, t, a) {
    function n() {
        c(".heart{width: 10px;height: 10px;position: fixed;background: #f00;transform: rotate(45deg);-webkit-transform: rotate(45deg);-moz-transform: rotate(45deg);}.heart:after,.heart:before{content: '';width: inherit;height: inherit;background: inherit;border-radius: 50%;-webkit-border-radius: 50%;-moz-border-radius: 50%;position: fixed;}.heart:after{top: -5px;}.heart:before{left: -5px;}"), o(), r()
    }

    function r() {
        for (var e = 0; e < d.length; e++) d[e].alpha <= 0 ? (t.body.removeChild(d[e].el), d.splice(e, 1)) : (d[e].y--, d[e].scale += .004, d[e].alpha -= .013, d[e].el.style.cssText = "left:" + d[e].x + "px;top:" + d[e].y + "px;opacity:" + d[e].alpha + ";transform:scale(" + d[e].scale + "," + d[e].scale + ") rotate(45deg);background:" + d[e].color + ";z-index:99999");
        requestAnimationFrame(r)
    }

    function o() {
        var t = "function" == typeof e.onclick && e.onclick;
        e.onclick = function (e) {
            t && t(), i(e)
        }
    }

    function i(e) {
        var a = t.createElement("div");
        a.className = "heart", d.push({
            el: a,
            x: e.clientX - 5,
            y: e.clientY - 5,
            scale: 1,
            alpha: 1,
            color: s()
        }), t.body.appendChild(a)
    }

    function c(e) {
        var a = t.createElement("style");
        a.type = "text/css";
        try {
            a.appendChild(t.createTextNode(e))
        } catch (t) {
            a.styleSheet.cssText = e
        }
        t.getElementsByTagName("head")[0].appendChild(a)
    }

    function s() {
        return "rgb(" + ~~(255 * Math.random()) + "," + ~~(255 * Math.random()) + "," + ~~(255 * Math.random()) + ")"
    }
    var d = [];
    e.requestAnimationFrame = function () {
        return e.requestAnimationFrame || e.webkitRequestAnimationFrame || e.mozRequestAnimationFrame || e.oRequestAnimationFrame || e.msRequestAnimationFrame || function (e) {
            setTimeout(e, 1e3 / 60)
        }
    }(), n()
}(window, document);
// alert("点击有惊喜");

var $ = {};
$.Particle = function (opt) {
    this.radius = 7;
    this.x = opt.x;
    this.y = opt.y;
    this.angle = opt.angle;
    this.speed = opt.speed;
    this.accel = opt.accel;
    this.decay = 0.01;
    this.life = 1;
};
$.Particle.prototype.step = function (i) {
    this.speed += this.accel;
    this.x += Math.cos(this.angle) * this.speed;
    this.y += Math.sin(this.angle) * this.speed;
    this.angle += $.PI / 64;
    this.accel *= 1.01;
    this.life -= this.decay;

    if (this.life <= 0) {
        $.particles.splice(i, 1);
    }
};
$.Particle.prototype.draw = function (i) {
    $.ctx.fillStyle = $.ctx.strokeStyle = 'hsla(' + ($.tick + (this.life * 120)) + ', 100%, 60%, ' + this
        .life + ')';
    $.ctx.beginPath();
    if ($.particles[i - 1]) {
        $.ctx.moveTo(this.x, this.y);
        $.ctx.lineTo($.particles[i - 1].x, $.particles[i - 1].y);
    }
    $.ctx.stroke();

    $.ctx.beginPath();
    $.ctx.arc(this.x, this.y, Math.max(0.001, this.life * this.radius), 0, $.TWO_PI);
    $.ctx.fill();

    var size = Math.random() * 1.25;
    $.ctx.fillRect(~~(this.x + ((Math.random() - 0.5) * 35) * this.life), ~~(this.y + ((Math.random() -
        0.5) * 35) * this.life), size, size);
}
$.step = function () {
    $.particles.push(new $.Particle({
        x: $.width / 2 + Math.cos($.tick / 20) * $.min / 2,
        y: $.height / 2 + Math.sin($.tick / 20) * $.min / 2,
        angle: $.globalRotation + $.globalAngle,
        speed: 0,
        accel: 0.01
    }));

    $.particles.forEach(function (elem, index) {
        elem.step(index);
    });

    $.globalRotation += $.PI / 6;
    $.globalAngle += $.PI / 6;
};
$.draw = function () {
    $.ctx.clearRect(0, 0, $.width, $.height);

    $.particles.forEach(function (elem, index) {
        elem.draw(index);
    });
};
$.init = function () {
    $.canvas = document.createElement('canvas');
    $.ctx = $.canvas.getContext('2d');
    $.width = 300;
    $.height = 300;
    $.canvas.width = $.width * window.devicePixelRatio;
    $.canvas.height = $.height * window.devicePixelRatio;
    $.canvas.style.width = $.width + 'px';
    $.canvas.style.height = $.height + 'px';
    $.ctx.scale(window.devicePixelRatio, window.devicePixelRatio);
    $.min = $.width * 0.5;
    $.particles = [];
    $.globalAngle = 0;
    $.globalRotation = 0;
    $.tick = 0;
    $.PI = Math.PI;
    $.TWO_PI = $.PI * 2;
    $.ctx.globalCompositeOperation = 'lighter';
    document.body.appendChild($.canvas);
    $.loop();
};
$.loop = function () {
    requestAnimationFrame($.loop);
    $.step();
    $.draw();
    $.tick++;
};
$.init();

function load_home() {
    document.getElementById("main").innerHTML = '<object type="text/html" data="/Users/lang/Desktop/demo/index.html" width="100%" height="600px"></object>';
}