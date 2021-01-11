$(function() {
    $("#panel-btn").click(function() {
      $("#panel").slideToggle(200);
      $("#panel-btn-icon").toggleClass("close");
      return false;
    });
  });