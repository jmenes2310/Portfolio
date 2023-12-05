package ar.jmenes.correlativasjmenes.model;

import java.util.ArrayList;
import java.util.Collection;

public class Curso {

    private String diaHorario;
    private Materia materia;
    private String anio;
    private Collection<Alumno> alumnos;

    public Curso(String diaHorario, Materia materia, String anio) {
        this.diaHorario = diaHorario;
        this.materia = materia;
        this.anio = anio;
        this.alumnos= new ArrayList<Alumno>();
    }

    public Curso(){
        super();
        this.alumnos= new ArrayList<Alumno>();
    }
    public String getDiaHorario() {
        return diaHorario;
    }

    public void setDiaHorario(String diaHorario) {
        this.diaHorario = diaHorario;
    }

    public Materia getMateria() {
        return materia;
    }

    public void setMateria(Materia materia) {
        this.materia = materia;
    }

    public String getAnio() {
        return anio;
    }

    public void setAnio(String anio) {
        this.anio = anio;
    }

    public Collection<Alumno> getAlumnos() {
        return alumnos;
    }

    public void setAlumnos(Collection<Alumno> alumnos) {
        this.alumnos = alumnos;
    }
}
