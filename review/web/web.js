login = () => {
    const id = document.getElementById('id').value;
    const password = document.getElementById('password').value;
    beforeValidation();
    // response를 받은 후 afterValidation()를 실행해 주세요;
    var path = '/check';
    const responseDiv = document.getElementById('response_msg');
    let answerInfo = new Object();
    fetch(path, {
        method: 'POST',
        headers: {'Content-Type': 'application/json'},
        body: JSON.stringify({ id: id, password: password })
     })
        .then(res => res.json())
        .then(ret => {
            var result;
            if(JSON.stringify(ret) === 'true')
              result = '정답입니다.';
            else
              result = '오답입니다.';
          document.getElementById('result').innerHTML = result;
        });
 }
 
 check = () => {
    beforeValidation();
    // response를 받은 후 afterValidation()를 실행해 주세요;
 }
 
 // 아래 함수를 수정 할 시, 채점과정에서 이상이 발생할 수 있습니다.
 beforeValidation = () => {
    const responseDiv = document.getElementById('response_msg');
    responseDiv.style.visibility = "hidden";
 }
 afterValidation = () => {
    const responseDiv = document.getElementById('response_msg');
    responseDiv.style.visibility = "visible";
 }

 function submit () {
    var path = '/submit';
    var checkboxes = document.getElementsByTagName('input');
    var dataArray = new Array;
    var answerInfo = new Object();
    for(var i = 0; i < checkboxes.length; i++){
        if(checkboxes[i].type === 'checkbox' && checkboxes[i].checked)
            dataArray.push(checkboxes[i].value);
    }
    answerInfo.answers = dataArray;
   fetch(path, {
      method: 'POST',
      headers: {'Content-Type': 'application/json'},
      body: JSON.stringify(answerInfo)
   })
      .then(res => res.json())
      .then(ret => {
          var result;
          if(JSON.stringify(ret) === 'true')
            result = '정답입니다.';
          else
            result = '오답입니다.';
        document.getElementById('result').innerHTML = result;
      });
};