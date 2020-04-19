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
  
  var randomn;
  $(document).ready(function(){
    var database = firebase.database();
    var slotnumber;
  
    database.ref().on("value", function(snap){

      slotnumber = snap.val().slotnumber;
      if (slotnumber == 1) {
        uid1 = snap.val().uid1;
        $("#uid").text(uid1);
        otp1 = snap.val().otp1;
        $("#otp").text(otp1);
      }
       else if (slotnumber == 2) {
        uid2 = snap.val().uid2;
        $("#uid").text(uid2);
        otp2 = snap.val().otp2;
        $("#otp").text(otp2);
      }
       else if (slotnumber == 3) {
        uid3 = snap.val().uid3;
        $("#uid").text(uid3);
        otp3 = snap.val().otp3;
        $("#otp").text(otp3);
      }
       else if (slotnumber == 4) {
        uid4 = snap.val().uid4;
        $("#uid").text(uid4);
        otp4 = snap.val().otp4;
        $("#otp").text(otp4);
      }
       else if (slotnumber == 5) {
        uid5 = snap.val().uid5;
        $("#uid").text(uid5);
        otp5 = snap.val().otp5;
        $("#otp").text(otp5);
      }
       else if (slotnumber == 6) {
        uid6 = snap.val().uid6;
        $("#uid").text(uid6);
        otp6 = snap.val().otp6;
        $("#otp").text(otp6);
      }

    });
  });