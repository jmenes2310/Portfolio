package ar.jmenes.correlativasjmenes;

import ar.jmenes.correlativasjmenes.model.Materia;
import ar.jmenes.correlativasjmenes.repositories.MateriaRepository;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

@SpringBootApplication
public class CorrelativasJmenesApplication {

	public static void main(String[] args) {
		SpringApplication.run(CorrelativasJmenesApplication.class, args);
	}

	@Bean
	public CommandLineRunner init(MateriaRepository repositorioMaterias){
		return (args)->{
			Materia analisis2 = new Materia("analisis 2","H3");
			Materia analisis1= new Materia("analsis 1","H1");
			Materia algebra = new Materia("algebra","H2");
			repositorioMaterias.save(analisis1);
			repositorioMaterias.save(algebra);
			repositorioMaterias.save(analisis2);
			repositorioMaterias.save(new Materia("algoritmos","SI2"));
			repositorioMaterias.save(new Materia("diseño de sistemas","SI6"));
			repositorioMaterias.save(new Materia("gestion de datos","SI12"));

			analisis2.addCorrelativa(analisis1);
			analisis2.addCorrelativa(algebra);

		};
	}

}
