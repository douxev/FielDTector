htot = 20;
diam=25;

difference()
{
    cylinder(h=htot,d=diam+2,$fn=50);
    
    union(){
    cylinder(h=(htot/2)-1,d=diam,$fn=50);
        translate([0,0,htot/2])
    cylinder(h=(htot/2)-1,d=diam,$fn=50);
    cylinder(h=htot-8,d=diam-3,$fn=50);
    }
}