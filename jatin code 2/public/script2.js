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
  
  function getRndInteger(min, max) {
    return Math.floor(Math.random() * (max - min + 1) ) + min;
  }
  var random1 = getRndInteger(1000,9999); 
  var random2 = getRndInteger(100,999);
  $(document).ready(function(){
    var database = firebase.database();
    var slotnumber;
  
    database.ref().on("value", function(snap){
        var firebaseRef1 = firebase.database().ref().child("p1");
        var firebaseRef2 = firebase.database().ref().child("p2");
        var firebaseRef3 = firebase.database().ref().child("p3");
        var firebaseRef4 = firebase.database().ref().child("p4");
        var firebaseRef5 = firebase.database().ref().child("p5");
        var firebaseRef6 = firebase.database().ref().child("p6");

        var firebaseRefotp1 = firebase.database().ref().child("otp1");
        var firebaseRefotp2 = firebase.database().ref().child("otp2");
        var firebaseRefotp3 = firebase.database().ref().child("otp3");
        var firebaseRefotp4 = firebase.database().ref().child("otp4");
        var firebaseRefotp5 = firebase.database().ref().child("otp5");
        var firebaseRefotp6 = firebase.database().ref().child("otp6");

        var firebaseRefuid1 = firebase.database().ref().child("uid1");
        var firebaseRefuid2 = firebase.database().ref().child("uid2");
        var firebaseRefuid3 = firebase.database().ref().child("uid3");
        var firebaseRefuid4 = firebase.database().ref().child("uid4");
        var firebaseRefuid5 = firebase.database().ref().child("uid5");
        var firebaseRefuid6 = firebase.database().ref().child("uid6");

      slotnumber = snap.val().slotnumber;
      if (slotnumber == 1) {
        $("#name1").text("Parking Slotnumber 1 is Booked For You");
        firebaseRef1.set(0);
        firebaseRefotp1.set(random1);
        firebaseRefuid1.set(random2);
      }
       else if (slotnumber == 2) {
        $("#name1").text("Parking Slotnumber 2 is Booked For You");
        firebaseRef2.set(0);
        firebaseRefotp2.set(random1);
        firebaseRefuid2.set(random2);
      }
       else if (slotnumber == 3) {
        $("#name1").text("Parking Slotnumber 3 is Booked For you");
        firebaseRef3.set(0);
        firebaseRefotp3.set(random1);
        firebaseRefuid3.set(random2);
      }
       else if (slotnumber == 4) {
        $("#name1").text("Parking Slotnumber 4 is Booked For You");
        firebaseRef4.set(0);
        firebaseRefotp4.set(random1);
        firebaseRefuid4.set(random2);
      }
       else if (slotnumber == 5) {
        $("#name1").text("Parking Slotnumber 5 is Booked For You");
        firebaseRef5.set(0);
        firebaseRefotp5.set(random1);
        firebaseRefuid5.set(random2);
      }
       else if (slotnumber == 6) {
        $("#name1").text("Parking Slotnumber 6 is Booked For You");
        firebaseRef6.set(0);
        firebaseRefotp6.set(random1);
        firebaseRefuid6.set(random2);
      }

    });
    $(".otp").click(function(){
          location.href = "otp.html";
      });
  });