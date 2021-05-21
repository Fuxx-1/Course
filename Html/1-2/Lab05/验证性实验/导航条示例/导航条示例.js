$(function () {
    var i = 1;
    $(".changeCss").click(function () {
        if (i++ % 2) {
            $("#nav li").each(function () {
                $(this).css("margin-right", "5px");
                $(this).css("float", "left");
                $(this).css("width", "100px");
                $(this).css("margin-top", "");
            });
        } else {
            $("#nav li").each(function () {
                $(this).css("margin-right", "");
                $(this).css("float", "");
                $(this).css("width", "");
                $(this).css("margin-top", "5px");
            });
        }
    });
})