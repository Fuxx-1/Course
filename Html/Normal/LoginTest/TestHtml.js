$(function () {
    $("img").attr("src", "https://dss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/u=3228549874,2173006364&fm=26&gp=0.jpg");

    function flush() {
        $.post("https://api.newimg.ltd/JavaWebDemo/Time", "",
            function (data, textStatus, jqXHR) {
                $("#successconnectinfo").text(data.info);
                $("#time").text("现在时间：" + data.time);
            },
        );
    }

    flush();

    $(".btn01").click(function () {
        $.post("https://api.newimg.ltd/JavaWebDemo/login", {
                signup: true,
                username: $("#username1").val(),
                passwd: $("#passwd1").val()
            },
            function (data, textStatus, jqXHR) {
                $(".info1").text(data.info);
                console.log(data);
                $("#passwd1").val("");
                flush();
            },
        );
        return false;
    });
    $(".btn02").click(function () {
        $.post("https://api.newimg.ltd/JavaWebDemo/login", {
                login: true,
                username: $("#username2").val(),
                passwd: $("#passwd2").val()
            },
            function (data, textStatus, jqXHR) {
                $(".info2").text(data.info);
                console.log(data);
                $("#passwd2").val("");
                flush();
            },
        );
        return false;
    });
});


// axios.get('http://127.0.0.1:8080/JavaWebDemo_war_exploded/hello-servlet')
//     .then((result) => {
//         var container = new Vue({
//             el: ".container",
//             data: {
//                 info: result.data,
//                 img: "https://dss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/u=3228549874,2173006364&fm=26&gp=0.jpg"
//             },
//         });
//         // console.log(result);
//     }).catch((err) => {
//         console.log(err);
//     });