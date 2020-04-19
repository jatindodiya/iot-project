var firebaseConfig = {
    apiKey: "AIzaSyBZdsVZ1-XPMb0KxegE6jqKaWt9Oxrdr-I",
    authDomain: "parking-tech-88362.firebaseapp.com",
    databaseURL: "https://parking-tech-88362.firebaseio.com",
    projectId: "parking-tech-88362",
    storageBucket: "parking-tech-88362.appspot.com",
    messagingSenderId: "92531599187",
    appId: "1:92531599187:web:c5315c6763071e7b92a3a6",
    measurementId: "G-T4PKT483SZ"
  };
  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);
  
  

  $(document).ready(function(){
    var database = firebase.database();
    var p1,p2,p3,p4,p5,p6;
  
    database.ref().on("value", function(snap){
      p1 = snap.val().p1;
      if(p1 == 1){
        $(".slotstatus1").text("Available");
      } else {
        $(".slotstatus1").text("Not Available");
      }
      p2 = snap.val().p2;
      if(p2 == 1){
        $(".slotstatus2").text("Available");
      } else {
        $(".slotstatus2").text("Not Available");
      }
      p3 = snap.val().p3;
      if(p3 == 1){
        $(".slotstatus3").text("Available");
      } else {
        $(".slotstatus3").text("Not Available");
      }
      p4 = snap.val().p4;
      if(p4 == 1){
        $(".slotstatus4").text("Available");
      } else {
        $(".slotstatus4").text("Not Available");
      }
      p5 = snap.val().p5;
      if(p5 == 1){
        $(".slotstatus5").text("Available");
      } else {
        $(".slotstatus5").text("Not Available");
      }
      p6 = snap.val().p6;
      if(p6 == 1){
        $(".slotstatus6").text("Available");
      } else {
        $(".slotstatus6").text("Not Available");
      }
    });

    $("#button1").click(function(){
      var firebaseRef = firebase.database().ref().child("slotnumber");
      if(p1 == 1){
        location.href = "map1.html";
        firebaseRef.set(1);
      } else {
        location.href = "#";
      }
    });
    $("#button2").click(function(){
      var firebaseRef = firebase.database().ref().child("slotnumber");
      if(p2 == 1){
        firebaseRef.set(2);
        location.href = "map1.html";
      } else {
        location.href = "#";
      }
    });
    $("#button3").click(function(){
      var firebaseRef = firebase.database().ref().child("slotnumber");
      if(p3 == 1){
        firebaseRef.set(3);
        location.href = "map1.html";
      } else {
        location.href = "#";
      }
    });
    $("#button4").click(function(){
      var firebaseRef = firebase.database().ref().child("slotnumber");
      if(p4 == 1){
        firebaseRef.set(4);
        location.href = "map1.html";
      } else {
        location.href = "#";
      }
    });
    $("#button5").click(function(){
      var firebaseRef = firebase.database().ref().child("slotnumber");
      if(p5 == 1){
        firebaseRef.set(5);
        location.href = "map1.html";
      } else {
        location.href = "#";
      }
    });
    $("#button6").click(function(){
      var firebaseRef = firebase.database().ref().child("slotnumber");
      if(p6 == 1){
        firebaseRef.set(6);
        location.href = "map1.html";
      } else {
        location.href = "#";
      }
    });
        
  });
 