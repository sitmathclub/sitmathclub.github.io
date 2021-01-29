jQuery(function(){
    var windowWidth = $(window).width();
    var headerHight = 100; 
    jQuery('a[href^=#]').click(function() {
    var speed = 1000;
    var href= jQuery(this).attr("href");
    var target = jQuery(href == "#" || href == "" ? 'html' : href);
    var position = target.offset().top-headerHight;
    jQuery('body,html').animate({scrollTop:position}, speed, 'swing');
    return false;
   });
});