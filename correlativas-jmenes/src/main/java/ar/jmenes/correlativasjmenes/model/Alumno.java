package ar.jmenes.correlativasjmenes.model;

import java.util.ArrayList;
import java.util.Collection;

public class Alumno {

    private String nombre;
    private String legajo;
    private Collection<Materia> materiasAprobadas;

    public Alumno(){
        super();
        this.materiasAprobadas = new ArrayList<Materia>();
    }
    public Alumno(String nombre, String legajo) {
        this.nombre = nombre;
        this.legajo = legajo;
        this.materiasAprobadas = new ArrayList<Materia>();
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getLegajo() {
        return legajo;
    }

    public void setLegajo(String legajo) {
        this.legajo = legajo;
    }

    public Collection<Materia> getMateriasAprobadas() {
        return materiasAprobadas;
    }

    public void setMateriasAprobadas(Collection<Materia> materiasAprobadas) {
        this.materiasAprobadas = materiasAprobadas;
    }
}
