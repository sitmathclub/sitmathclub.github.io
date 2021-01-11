/*「サイト表示時にTransitionでホバーアニメーションが実行されてしまう場合の対処法」(https://webrandum.net/transition-execute-error/)より*/
window.onload = function () {
    const preload = document.getElementsByClassName('preload');
    preload[0].classList.remove('preload');
}