$(function () {
    var i = 4;
    $(".Add").click(function () {
        $("<div><input type=\"checkbox\">文件" + i++ + "</div>").appendTo('.element');
        isChecked();
        divChecked();
    });
    $(".Del").click(function () {
        $(".element div:last-child").remove();
        i--;
    });
    $(".DelSel").click(function () {
        $(".element div").each(function () {
            if ($(this).find("input").first().prop('checked')) {
                $(this).remove();
            }
        });
    });
    isChecked();
    divChecked();
});

function isChecked() {
    $(":checkbox").click(function () {
        // this.prop("checked", true);
        changeCss();
    });
}

function changeCss() {
    $(".element div").each(function () {
        if ($(this).find("input").first().prop('checked')) {
            $(this).css("background", "#33ff00");
        } else {
            $(this).css("background", "");
        }
    });
}

function divChecked() {
    // $(".element div").each(function () {
    //     var count = 1;
    //     $(this).click(function () {
    //         var $input = $(this).find("input");
    //         if (count % 2 == 0) {
    //             $input.prop("checked", false);
    //         } else {
    //             $input.prop("checked", true);
    //         }
    //         count++;
    //         changeCss();
    //     });
    // });
    $(".element div").click(function () {
        $(".element div").each(function () {
                $(this).css("background", "");
        });
        changeCss();
        if ($(this).find("input").first().prop('checked')) {
            $(this).css("background", "#33ff00");
        } else {
            $(this).css("background", "#c2c2c2");
        }
    });
}