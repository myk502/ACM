bool InTriangle(Point p,Point q,Point r,Point s)
{
    bool pqleft=ToLeft(p,q,s);
    bool qrleft=ToLeft(q,r,s);
    bool rpleft=ToLeft(r,p,s);
    return((pqleft==qrleft)&&(qrleft==rpleft));
}
