$(function() {
    var User = new Vue({
        el: ".User",
        data: {
            Avatar: "https://dss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/u=3228549874,2173006364&fm=26&gp=0.jpg",
            username: "sdkljf"
        }
    });
    var FrindCircleInfo = new Vue({
        el: ".Content",
        data: {
            Info: [
                {
                    AvatarImgSrc: "https://dss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/u=3228549874,2173006364&fm=26&gp=0.jpg",
                    username: "Hello",
                    UserContent: "浮动框旁边的行框被缩短,从而给浮动框留出空间,行框围绕浮动框。 因此,创建浮动框可以使文本围绕图像: 要想阻止行框围绕浮动框,需要对该框应用 clear 属性。",
                    time: "10分钟",
                    likes: "User1, User2",
                    commit: [{
                            username: "User1",
                            commitcontent: "： 真不错"
                        },
                        {
                            username: "User1",
                            commitcontent: "： 真不错"
                        }
                    ]
                },
                {
                    AvatarImgSrc: "https://dss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/u=3228549874,2173006364&fm=26&gp=0.jpg",
                    username: "Hello",
                    UserContent: "浮动框旁边的行框被缩短,从而给浮动框留出空间,行框围绕浮动框。 因此,创建浮动框可以使文本围绕图像: 要想阻止行框围绕浮动框,需要对该框应用 clear 属性。",
                    time: "10分钟",
                    likes: "User1, User2",
                    commit: [{
                            username: "User1",
                            commitcontent: "： 真不错"
                        },
                        {
                            username: "User1",
                            commitcontent: "： 真不错"
                        }
                    ]
                },
                {
                    AvatarImgSrc: "https://dss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/u=3228549874,2173006364&fm=26&gp=0.jpg",
                    username: "Hello",
                    UserContent: "浮动框旁边的行框被缩短,从而给浮动框留出空间,行框围绕浮动框。 因此,创建浮动框可以使文本围绕图像: 要想阻止行框围绕浮动框,需要对该框应用 clear 属性。",
                    time: "10分钟",
                    likes: "User1, User2",
                    commit: [{
                            username: "User1",
                            commitcontent: "： 真不错"
                        },
                        {
                            username: "User1",
                            commitcontent: "： 真不错"
                        }
                    ]
                },
                {
                    AvatarImgSrc: "https://dss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/u=3228549874,2173006364&fm=26&gp=0.jpg",
                    username: "Hello",
                    UserContent: "浮动框旁边的行框被缩短,从而给浮动框留出空间,行框围绕浮动框。 因此,创建浮动框可以使文本围绕图像: 要想阻止行框围绕浮动框,需要对该框应用 clear 属性。",
                    time: "10分钟",
                    likes: "User1, User2",
                    commit: [{
                            username: "User1",
                            commitcontent: "： 真不错"
                        },
                        {
                            username: "User1",
                            commitcontent: "： 真不错"
                        }
                    ]
                },
            ]
        }
    })
})