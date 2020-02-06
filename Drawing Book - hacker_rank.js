	
  function pageCount1(n, p){
    var turns = 0;
     /* Sean n=2k+1 o n=2k y p=2t o p=2t+1.
    Teniendo en cuenta que en la misma pag de 1 está 0. */
    if(p <= Math.floor(n/2)){
      turns = Math.floor(p/2);
    /* En este caso tenemos que p <= k.
      Por lo que turns <= k desde pag 1 y
      turns >= k desde pag n.
      La diferencia entre pag 1 y pag p es t = floor(p/2). */
    }
    else if(n%2==1){
      turns = Math.floor((n-p)/2);
    }
    else {
      turns = Math.ceil((n-p)/2);
    }

    return turns;
}

function pageCount2(n, p) {
   
    var turns = 0;

    /* Sean n=2k+1 o n=2k y p=2t o p=2t+1.
    Teniendo en cuenta que en la misma pag de 1 está 0. */
    if(p <= Math.floor(n/2)){
      turns = Math.floor(p/2);
      /* En este caso tenemos que p <= k.
      Por lo que turns <= k desde pag 1 y
      turns >= k desde pag n.
      La diferencia entre pag 1 y pag p es t = floor(p/2). */
    }
    else {
      turns = Math.floor(n/2) - Math.floor(p/2);
      /* En caso de que p>k, turns >= k desde pag 1,
      por lo que turns <= k desde pag n.
      Tendremos que la diferencia entre la pag n y 
      la pag p es k-t=floor(n/2)-floor(p/2).*/
    }
    return turns;
}